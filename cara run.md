1.	Compile program dengan perintah: gcc 2208107010058_Simple_Sorting.c -o 2208107010058_Simple_Sorting 
2.	Jalankan program dengan perintah: ./2208107010058_Simple_Sorting.
3.	Tunggu hingga proses sorting dan pencatatan waktu selesai.
4.	Hasil sorting dan waktu eksekusi akan disimpan dalam file teks yang sesuai.
   
Fungsi-fungsi dalam Kode Program:
1.	generateRandomNumbers(int *array, int size, int num):
Fungsi ini digunakan untuk menghasilkan bilangan acak sebanyak size dan menyimpannya dalam array. Bilangan acak kemudian disimpan dalam file teks dengan format num_input.txt, di mana num adalah parameter yang diberikan.

2.	bubbleSort(int *array, int size):
Fungsi ini mengimplementasikan algoritma Bubble Sort untuk mengurutkan array secara ascending.

3.	selectionSort(int *array, int size):
Fungsi ini mengimplementasikan algoritma Selection Sort untuk mengurutkan array secara ascending.

4.	insertionSort(int *array, int size):
Fungsi ini mengimplementasikan algoritma Insertion Sort untuk mengurutkan array secara ascending.

5.	saveSortedToFile(char *filename, int *array, int size, double time):
Fungsi ini digunakan untuk menyimpan array yang telah diurutkan dan waktu eksekusi sorting ke dalam file teks. Nama file disesuaikan dengan parameter filename yang diberikan.

6. main():
Fungsi utama yang mengatur alur eksekusi program.
Looping dilakukan untuk setiap jenis algoritma sorting (Bubble Sort, Selection Sort, Insertion Sort) dan untuk setiap ukuran array mulai dari 100.000 hingga 1.000.000 dengan interval 100.000.
Setiap iterasi melakukan sorting array acak, mengukur waktu eksekusi, dan menyimpan hasil sorting beserta waktu eksekusi ke dalam file teks yang sesuai.
