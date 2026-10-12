# Informed Search: Greedy Best-First Search (GBFS) & A\* (A-Star) - Pacman Problem

Repitori ini berisi implementasi dan laporan perbandingan dua algoritma _Informed Search_—yaitu **Greedy Best-First Search (GBFS)** dan **A\***—dalam menyelesaikan permasalahan pencarian jalur pada _Pacman Problem_.

Proyek ini dikerjakan oleh **Kelompok 4**:

- **Muhammad Naufal Syahputra** (5025251075)
- **Yudith Hafiz Rabbani** (5025251100)
- **Muhammad Afzal Fulvian Handoni** (5025251125)

---

## 🧠 Tentang Permasalahan & Algoritma

### 1. Pacman Problem

_Pacman Problem_ adalah studi kasus pencarian jalur (_pathfinding_) dari titik awal (`S` / _Start_) ke titik tujuan (`G` / _Goal_) pada sebuah grid, menghindari rintangan (`#`), serta memperhitungkan bobot atau biaya (_cost_ 1-9) pada setiap langkah.

### 2. Fungsi Heuristik

Kedua algoritma menggunakan jarak Manhattan (_Manhattan Distance_) sebagai fungsi heuristik $h(n)$ untuk mengestimasi jarak dari posisi saat ini ke tujuan:
$$h(n) = |x_n - x_{goal}| + |y_n - y_{goal}|$$

### 3. Perbandingan Algoritma

- **Greedy Best-First Search (GBFS):** Menggunakan fungsi evaluasi $f(n) = h(n)$. Algoritma ini selalu memilih node dengan nilai heuristik terkecil. Proses pencarian cenderung lebih cepat dan mengunjungi node lebih sedikit, namun **tidak menjamin** menemukan jalur dengan biaya paling optimal.
- **A\* (A-Star Search):** Menggunakan fungsi evaluasi $f(n) = g(n) + h(n)$, yang menggabungkan biaya aktual yang telah ditempuh $g(n)$ dan estimasi sisa biaya $h(n)$. Algoritma ini **dijamin optimal** (dengan heuristik yang _admissible_).

---

## 📊 Ringkasan Hasil Perbandingan (Berdasarkan Laporan)

| Aspek                      | Greedy Best-First Search (GBFS)                                    | A* Search ($A^*$)                                      |
| :------------------------- | :----------------------------------------------------------------- | :----------------------------------------------------- |
| **Fungsi Evaluasi**        | $f(n) = h(n)$                                                      | $f(n) = g(n) + h(n)$                                   |
| **Informasi yang Dipakai** | Hanya estimasi jarak ke _goal_                                     | Biaya riil yang ditempuh + estimasi jarak ke _goal_    |
| **Optimalitas Jalur**      | Tidak dijamin                                                      | Dijamin optimal                                        |
| **Jumlah Node Dikunjungi** | Umumnya lebih sedikit / cepat                                      | Cenderung lebih banyak (mengeksplorasi alternatif)     |
| **Karakteristik**          | Cocok untuk solusi cepat saat kualitas jalur bukan prioritas utama | Cocok untuk mencari jalur berbiaya minimal yang akurat |

---

## 📄 Laporan Lengkap

Dokumen laporan lengkap terkait analisis eksperimen, _testcase_ (1 sampai 6), serta visualisasi peta hasil pencarian dapat dibaca pada file PDF:  
[`Kelompok 4_Informed Search_Pacman Problem.pdf`](./Kelompok%204_Informed%20Search_Pacman%20Problem.pdf)
