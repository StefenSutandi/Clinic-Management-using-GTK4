// Tutorial Compile Program C

1.	Pastikan Anda telah memiliki program compiler C di Windows anda (GNU untuk Linux/MacOs dan MinGW untuk Windows).
2.	Download berbagai file yang digunakan untuk mengcompile dan jalankan program dengan ketik di terminal :
“gcc func.c main.c -o klinik.c”
3.	Jalankan file .exe dengan mengetik “./klinik”
4.	Dari terminal akan muncul, berbagai pilihan menu dan pilihlah menu yang ingin dijalankan, asumsikan input yang dimasukkan harus valid (sesuai spesifikasi) agar program yang dijalankan dapat berfungsi dengan baik.
5.	Jika sudah selesai, pilihlah menu di nomor 16 atau bisa menggunakan “Ctrl + C” untuk menghentikan program.
6.	Selesai.

// Tutorial Compile GUI

*Kondisi Jika Belum Memiliki GTK4
1.	Unduh MSYS2 installer dari situs berikut https://www.msys2.org/ 
2.	Buka MSYS2 shell dan ketik perintah ini “pacman -S mingw-w64-x86_64-gtk4”
3.	Buka MYSYS2 MINGW64 dan ketik perintah ini “pacman -S mingw-w64-x86_64-toolchain base-devel”
4.	Buka “Edit the system environtment variables”
5.	Klik “Environtment Variables”, terdapat 2 jendela yaitu User Variables for.. dan System variables. Keduanya memiliki variable “Path”, klik edit.
6.	Tambahkan path dari msys berada misalnya “C:\msys64\mingw64\bin" dengan mengeklik “new”. Klik OK dan tambahkan pada kedua variable path tersebut.

Kondisi Jika Sudah Memiliki GTK4
1.	Unduh file secara utuh dari link berikut https://github.com/StefenSutandi/TugasBesarPMC5 dan ekstrak.
2.	Buka VSCODE -> Open Folder -> TugasBesarPMC5 -> GUI Klinik -> Open Folder.
3.	Buka source code “GUI_Klinik.c” dan tekan “Shift + CTRL + B”. 
4.	Jika muncul pesan error maka buka folder “Setting” yang berisi file berekstensi “.json”
5.	Salin seluruh file, pindahkan dan timpa ke dalam folder “.vscode”.
6.	Buka source code “GUI_Klinik.c” tekan “Shift + CTRL + B”. 
7.	Selesai
