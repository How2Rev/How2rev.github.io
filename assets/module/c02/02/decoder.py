import pathlib
from PIL import Image
encrypted = pathlib.Path('dump.rom').read_bytes()

KEY = b'Sinnesl\xf6schenInc'
rom = bytes(a ^b for a,b in zip(encrypted, KEY*len(encrypted)))

with open("rom.decrypted","wb") as fd:
    fd.write(rom)

class VM:
    def __init__(self, endian):
        self.mem = bytearray(rom.ljust(16*1024, b'\x00'))
        self.a = 0
        self.b = 0
        self.ip = 0
        self.endian = endian
        self.screen = Image.new("1", (128, 128), 1)

    def tiled(self, source: int, size: int):
        print(f'Treating mem[{source:#x}] as tiled image of size {size}x{size}')
        assert self.endian in ('little', 'big')
        tile_index = 0
        for t_row in range(0, size, 4):
            for t_col in range(0, size, 4):
                raw = self.mem[source + tile_index * 2:source + tile_index * 2 + 2]
                assert len(raw) == 2
                tile_data = int.from_bytes(raw, self.endian) 
                tile_index += 1
                bit_index = 0
                for p_row in range(4):
                    for p_col in range(4):
                        bit = (tile_data >> bit_index) & 1 
                        self.screen.putpixel((t_col + p_col, t_row + p_row), bit)
                        bit_index += 1
                assert bit_index == 16
        self.screen.save("flag.jpg")

    def get_reg(self, idx):
        assert(idx <= 1)
        return [self.a, self.b][idx]
    
    def set_reg(self, idx, v):
        assert(idx <=1)
        v &= 0xffff
        if idx:
            self.b = v
        else:
            self.a = v

    def set_reg_or_mem(self, idx, v):
        assert(idx <= 3)
        if idx & 2:
            reg = self.get_reg(idx & 1)
            self.mem[reg:reg+1] = v.to_bytes(2, self.endian)

        else:
            self.set_reg(idx & 1, v)        

    def get_reg_or_mem(self, idx):
        assert(idx <=3)
        reg = self.get_reg(idx & 1)
        if idx & 2:
            return int.from_bytes(self.mem[reg:reg+2], self.endian)
        else:
            return reg

    def step(self):
        insn = self.mem[self.ip]
        insn_as_bits = f"{insn:08b}"

        op = insn >> 4 & 0xf
        ra_a = (insn >> 2) & 0x3
        ra_b = insn & 0x3
        match op:
            case 0b0011: 
                print("xor")
                self.set_reg_or_mem(ra_a, self.get_reg_or_mem(ra_a) ^ self.get_reg_or_mem(ra_b))
            case 0b0000: #HLT
                print("halt")
                return False
            case 0b0001:
                print("screen")
                source = self.get_reg_or_mem(ra_a)
                match ra_b:
                    case 0b00:
                        print("bitplane64")
                    case 0b01:
                        print("tilted64")
                    case 0b10:
                        print("bitplane128")
                    case 0b11:
                        print("tilted128")
                        self.tiled(source, 128)
                pass
            case 0b0010:
                print("note")
            case _:
                reg = (insn >> 6) & 1
                value = ((insn & 0x3f) << 8) | self.mem[self.ip+1]
                self.set_reg(reg, self.get_reg(reg) ^ value)
                self.ip +=1

        self.ip +=1 
        return True

    def run(self):
        while True:
            if not self.step():
                break



vm = VM("big")
vm.run()