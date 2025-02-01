---
layout: default
---

# Recommended Resources:

- [Tool: ADB](https://developer.android.com/tools/adb?hl=fr)
- [Tool: Android Studio](https://developer.android.com/studio?hl=fr)
- [Post EN: Android reversing](https://www.corellium.com/blog/android-mobile-reverse-engineering)
- [Tool: Android Reversing Tool list](https://github.com/user1342/Awesome-Android-Reverse-Engineering)

# Structure of an Android App Binary (.apk)

An `.apk` file is an Android binary. APK stands for **Android Package Kit** (also **Android Application Package**) and is the file format Android uses to distribute and install Android apps. It contains all the elements an app needs to function correctly on your device.

# About .apk files

Android applications are bundled in a single file type called **APK** (Android Package Kit). They come with an `.apk` suffix but are just ZIP files. If you modify the suffix, you can extract their contents. To be more precise, an APK is a type of **JAR** (Java ARchive), which is a type of ZIP.

The contents of the `.apk` file always fit a specific structure:

![Picture1-768x812](/pages/C04/img/android/Picture1-768x812.png)

- **META-INF** – This folder contains verification information and is generated when “signing” the application. It is basically the fingerprint information for every file contained within the APK, meaning that any modification to the APK (even replacing an icon) requires resigning the APK. Otherwise, the OS will reject the installation. When signing applications, these files are updated.
    - The contents of this folder are:
        - **CERT.SF** (May have another file name with the same suffix) – List of all files with their SHA-1 hashes.
        - **CERT.RSA** (May have another file name with the same suffix) – Contains signed content of CERT.RF and is used to verify app integrity with the public key.
        - **MANIFEST.MF** – Contains the SHA-256-Digest of all the files in the apk. It is used to verify the validity of each file in the zip, ensuring that altering this file or any other files in the zip container will revoke the signature and make it invalid.
- **assets** – The developer controls application resources in the folder hierarchy. For example, if your application displays a video or comes with some document templates, they will be stored in the assets folder. In addition, certain frameworks also use the assets folder to store code and data. For example:
    - Cordova or React-native applications store their Javascript code in the assets folder.
    - Maui, Xamarin applications store DLL files in the assemblies folder, which acts in the same manner.
- **AndroidManifest.xml** – A required file that describes the application. The manifest contains key information elements about the application. Here’s a partial list of them:
    - Application’s package name.
    - All the application’s components, such as activities and resources.
    - The permissions this application requires to run and the permissions required to access this application’s information by other apps.
    - Compatibility features (e.g., minimum Android version and supported devices).
    - A complete specification can be found [here](https://developer.android.com/guide/topics/manifest/manifest-intro).

As part of the Fusion process, the binary representation of the `AndroidManifest.xml` usually changes as Appdome adjusts the file to support the selected settings.

Incidentally, Appdome’s **TOTALCode**, and more specifically **Encrypt Strings and Resources** and **Non-Native Code Obfuscation** switches to seek out those files when obfuscating the application’s code and alters them as part of the fusion process.

In addition, as part of the fusion process, some assets may be added to store information related to Fusion and the selected policy.
- **classes.dex** – Google’s proprietary format for their version of the Java VM, contains all Java/Kotlin code compiled to their specific bytecode called Dalvik. APK files may contain more than one `classes.dex` file due to limitations of the DEX format. Additional files will be numbered (i.e., `classes2.dex`, `classes3.dex` and so forth). As part of the fusion process, Appdome adds at least one more `classes.dex` containing only the selected policy. The application’s original `classes.dex` is also altered as part of the fusion process. Appdome’s **Flow Relocation** will obfuscate the original application’s code flow within the dex files.
- **kotlin** – This folder is present only if the application was written with Kotlin. It contains Kotlin-specific data. Depending on the selected Fusion policy, its content might change as part of the fusion process.
- **lib** – A folder that contains native libraries (machine code). Since Android is cross-platform, it contains a subfolder for each supported processor:
    - **armabi** – Binaries that support at least ARMv5TE, deprecated since ndkr16 (Dec. 2017) and removed in ndkr17 (Jun. 2018).
    - **armeabi-v7a** – Binaries supporting ARMv7.
    - **arm64-v8a** – Binaries supporting ARMv8.
    - **x86** – Binaries supporting x86.
    - **x86_64** – Binaries supporting x86-64.
    - **mips** – Binaries for MIPS, deprecated since ndkr17.
    - The presence or lack of a subfolder indicates the support (or lack thereof) for that platform. For example, if there’s an `x86_64` subfolder, the application will be compatible with the Android emulator.
    - Appdome’s **Binary Code Obfuscation** will encrypt these files to protect them from reverse engineering.

More info about supported ABI’s can be found [here](https://developer.android.com/ndk/guides/abis).

- **res** – A folder that contains resources (like assets) but with a pre-defined folder hierarchy that the developer can’t change. These files are used to provide alternatives for different screen orientations, OS versions, and multi-language support. During the Fusion process, Appdome unpacks and repacks the resource folder, so its binary representation of the `.xml` files or nine-patch png files may change. Depending on the third-party SDKs and UI/Networking resources added to the application according to the customer-selected Fusion set, more files may be added to this folder, and the content of files may change as well.
- **resources.arsc** – A file that contains information that links the code (`classes.dex`) to the resources (`res`). For example, the code might reference the text of a dialog, while the resources contain that text in all languages. The Android OS then chooses the correct language according to the device’s locale configuration. During the Fusion process, Appdome unpacks and repacks the resource folder, so its binary representation usually changes.


# C04 - 01 : Android Rev V01 (Easy--)

In this challenge, the goal is to reverse engineer an Android application that stores its password hardcoded in the main app. Right now, the secret data is quite easy to get, for now...

flag format is LRCTF{ascii}

[C04-01: android01.apk](/assets/module/c04/01/android01.apk)  

# C04 - 02 : Android Rev V02 (Easy+)

We fired the old developer who stored a password in the source code like this. 
Now, the new developer has stored the password encrypted in a secure context!

flag format is LRCTF{ascii}

[C04-02: android02.apk](/assets/module/c04/01/android02.apk)  


