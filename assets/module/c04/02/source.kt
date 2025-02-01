package com.le.how2rev02

import android.content.Context
import android.os.Bundle
import android.util.Base64
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.text.BasicTextField
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import com.le.how2rev02.ui.theme.How2rev02Theme
import javax.crypto.Cipher
import javax.crypto.spec.SecretKeySpec
import javax.crypto.spec.IvParameterSpec

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            How2rev02Theme {
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    Box(
                        modifier = Modifier.fillMaxSize(),
                        contentAlignment = Alignment.Center
                    ) {
                        LoginScreen(this@MainActivity)
                    }
                }
            }
        }
    }
}

@Composable
fun LoginScreen(context: Context) {
    var username by remember { mutableStateOf("admin") }
    var password by remember { mutableStateOf("?") }
    var message by remember { mutableStateOf("") }

    val keyString = context.getString(R.string.k)

    val storedPasswordEncrypted = "35E809B9B2639725BE47D0139B67A82F0B65AC511544B82D0287F7B70C5DCFAF"

    Column(
        modifier = Modifier.padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(text = "Login", style = MaterialTheme.typography.headlineMedium)
        Spacer(modifier = Modifier.height(8.dp))

        BasicTextField(
            value = username,
            onValueChange = { username = it },
            modifier = Modifier.fillMaxWidth(),
            decorationBox = { innerTextField ->
                Box(modifier = Modifier.padding(8.dp)) { innerTextField() }
            }
        )
        Spacer(modifier = Modifier.height(8.dp))

        BasicTextField(
            value = password,
            onValueChange = { password = it },
            modifier = Modifier.fillMaxWidth(),
            decorationBox = { innerTextField ->
                Box(modifier = Modifier.padding(8.dp)) { innerTextField() }
            }
        )
        Spacer(modifier = Modifier.height(8.dp))

        Button(onClick = {
            val uE = AES_encrypt(password, keyString)
            Log.i("how2rev02", uE)
            Log.i("how2rev02", storedPasswordEncrypted)
            Log.i("how2rev02", (uE==storedPasswordEncrypted).toString());
            message = if (uE == storedPasswordEncrypted) {
                "Login Successful"
            } else {
                "Invalid Credentials"
            }
        }) {
            Text("Login")
        }

        Spacer(modifier = Modifier.height(8.dp))
        Text(text = message, style = MaterialTheme.typography.bodyMedium)
    }
}

fun AES_encrypt(input: String, key: String): String {
    val cipher = Cipher.getInstance("AES/CBC/PKCS5Padding")
    val secretKey = SecretKeySpec(key.toByteArray(), "AES")
    val iv = IvParameterSpec(ByteArray(16))
    cipher.init(Cipher.ENCRYPT_MODE, secretKey, iv)
    val encryptedBytes = cipher.doFinal(input.toByteArray())
    return encryptedBytes.joinToString("") { String.format("%02X", it) }
}