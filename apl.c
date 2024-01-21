#include <stdio.h>
#include <string.h>

#define max_ikan 100
#define max_trans 100 

struct ikan
{
    char nama[50];
    int jenis;
    int harga;
};

struct transaction {
    char kustomer[100];
    char nama_ikan[50];
    int jumlah;
    int total;
};

struct ikan tambah_ikan(struct ikan iwak[], int jmlh_ikan) { // fungsi
    printf("Nama ikan: \n");
    scanf(" %[^\n]s", iwak[jmlh_ikan].nama);
    // scanf(" %[^\n]s", iwak[jmlh_ikan].nama); 
    /* String format %[^\n]s digunakan untuk membaca string dari input pengguna hingga karakter newline (\n) ditemukan. 
    Karakter newline tidak disimpan dalam variabel iwak[jmlh_ikan].nama. Tanda ^ menunjukkan bahwa karakter newline tidak termasuk dalam karakter yang dibaca 
    oleh scanf(). Karakter s pada akhir string format menunjukkan bahwa karakter newline akan dibuang. */

    /* Spasi yang diletakkan sebelum % pada scanf() digunakan untuk mengabaikan karakter whitespace (spasi, tab, newline) 
    yang mungkin tersisa pada buffer input sebelum string yang diminta. Jika spasi tersebut tidak diletakkan, 
    maka scanf() akan membaca karakter whitespace tersebut sebagai bagian dari string yang diminta. */

    iwak[jmlh_ikan].jenis = 2;
    while((iwak[jmlh_ikan].jenis != 0) && (iwak[jmlh_ikan].jenis != 1)) {
        printf("Jenis ikan Tawar/Laut (0/1): \n");
        scanf("%d", &iwak[jmlh_ikan].jenis);
    }

    printf("Harga ikan: \n");
    scanf("%d", &iwak[jmlh_ikan].harga);

    return iwak[jmlh_ikan];
}

void list_ikan(struct ikan iwak[], int jmlh_ikan) {
    printf("------------------------- List Ikan -------------------------\n");
    printf("%-20s %-20s %-20s\n", "Nama Ikan", "Jenis Ikan", "Harga Ikan");

    for (int i = 0; i < jmlh_ikan; i++)
    {
        char jeniss[10];
        if (iwak[i].jenis == 0)
        {
            strcpy(jeniss, "Tawar");
        } else if(iwak[i].jenis == 1) {
            strcpy(jeniss, "Laut");
        }
        
        printf("%-20s %-20s %-20d\n", iwak[i].nama, jeniss, iwak[i].harga);
    }
    printf("\n\n");
    
}

void transaksi_ikan(struct ikan iwak[], int jmlh_ikan, struct transaction trans[], int *jmlh_trans) {
    printf("------------------------- Transaksi -------------------------\n");
    printf("Masukkan Nama Customer: \n");
    scanf(" %[^\n]s", trans[*jmlh_trans].kustomer);

    // int i = 0;
    while (*jmlh_trans < max_trans)
    {
        int temp = *jmlh_trans;
        printf("Masukkan nama ikan yang ingin dibeli (ketik 'done' jika ingin menyelesaikan transaksi): \n");
        scanf(" %[^\n]s", trans[*jmlh_trans].nama_ikan);

        if(strcmp(trans[*jmlh_trans].nama_ikan, "done") == 0)
        /* fungsi strcmp() berfungsi untuk membandingkan 2 buah string, akan mengembalikan nilai 0 jika kedua string sama dan nilai
        selain 0 jika kedua string berbeda */
        {
            break;
        }

        printf("Masukkan jumlah ikan yang ingin dibeli: \n");
        scanf("%d", &trans[*jmlh_trans].jumlah);        

        for (int i = 0; i < jmlh_ikan; i++) // searching
        {
            if(strcmp(trans[*jmlh_trans].nama_ikan, iwak[i].nama) == 0) {
                trans[*jmlh_trans].total = iwak[i].harga * trans[*jmlh_trans].jumlah;
            }
        }

        (*jmlh_trans)++;
        strcpy(trans[*jmlh_trans].kustomer, trans[temp].kustomer);
    }
    
}

void riwayat(struct transaction trans[], int jmlh_trans) {
    printf("------------------------- Riwayat Transaksi -------------------------\n");
    printf("%-20s %-20s %-20s %-20s\n", "Kustomer", "Nama Ikan", "Jumlah", "Total");

    int i;
    for (i = 0; i < jmlh_trans; i++)
    {
        printf("%-20s %-20s %-20d %-20d\n", trans[i].kustomer, trans[i].nama_ikan, trans[i].jumlah, trans[i].total);
    }
    printf("\n\n");
    
}

void search_ikan_nama(struct ikan iwak[], int jmlh_ikan) {
    printf("------------------------- Search Ikan Berdasar Nama -------------------------\n");

    char inputanNama[50];
    printf("Masukkan Nama Ikan: \n");
    scanf(" %[^\n]s", inputanNama);

    char jeniss[50];
    printf("\n%-20s %-20s %-20s\n", "Nama Ikan", "Jenis Ikan", "Harga Ikan");
    for (int i = 0; i < jmlh_ikan; i++)
    {
        if(strcmp(iwak[i].nama, inputanNama) == 0) {
            if (iwak[i].jenis == 0)
            {
                strcpy(jeniss, "Tawar");
            } else if (iwak[i].jenis == 1) {
                strcpy(jeniss, "Laut");
            }
            printf("%-20s %-20s %-20d\n", iwak[i].nama, jeniss, iwak[i].harga);
        }
    }
    printf("\n\n");
}

void search_jenis_ikan(struct ikan iwak[], int jmlh_ikan) {
    printf("------------------------- Filter Ikan Berdasar Jenis -------------------------\n");

    char jeniss[50];
    printf("Masukkan jenis ikan (Tawar/tawar/Laut/laut): \n");
    scanf(" %[^\n]s", jeniss);

    int jeniss2;
    if((strcmp(jeniss, "Tawar") == 0) || (strcmp(jeniss, "tawar") == 0)) {
        jeniss2 = 0;
    } else if((strcmp(jeniss, "Laut") == 0) || strcmp(jeniss, "laut") == 0) {
        jeniss2 = 1;
    } else {
        printf("Jenis yang anda inputkan salah\n");
    }

    printf("\n%-20s %-20s %-20s\n", "Nama Ikan", "Jenis Ikan", "Harga Ikan");
    for (int i = 0; i < jmlh_ikan; i++)
    {
        if (iwak[i].jenis == jeniss2)
        {
            printf("%-20s %-20s %-20d\n", iwak[i].nama, jeniss, iwak[i].harga);
        }
    }
    printf("\n\n");
}

void sorting_termahal(struct ikan iwak[], int jmlh_ikan) { // selection sort
    printf("------------------------- List Ikan -------------------------\n");
    for(int i = 0; i < jmlh_ikan; i++) {
        int i_max = i;
        for(int j = i_max; j < jmlh_ikan; j++) {
            if(iwak[j].harga > iwak[i_max].harga) {
                i_max = j;
            }
        }
        struct ikan temp = iwak[i_max];
        iwak[i_max] = iwak[i];
        iwak[i] = temp;
    }

    printf("\n%-20s %-20s %-20s\n", "Nama Ikan", "Jenis Ikan", "Harga Ikan");
    for (int i = 0; i < jmlh_ikan; i++)
    {
        char jeniss[10];
        if (iwak[i].jenis == 0)
        {
            strcpy(jeniss, "Tawar");
        } else if(iwak[i].jenis == 1) {
            strcpy(jeniss, "Laut");
        }
        printf("%-20s %-20s %-20d\n", iwak[i].nama, jeniss, iwak[i].harga);
    }
    printf("\n\n");
    
}

void sorting_termurah(struct ikan iwak[], int jmlh_ikan) { // bubble sort
    printf("------------------------- List Ikan -------------------------\n");
    for(int i = 0; i < jmlh_ikan; i++) {
        for(int j = 0; j < jmlh_ikan - 1; j++) {
            if(iwak[j].harga > iwak[j + 1].harga) {
                struct ikan temp = iwak[j + 1];
                iwak[j + 1] = iwak[j];
                iwak[j] = temp;
            }
        }
    }
    
    printf("\n%-20s %-20s %-20s\n", "Nama Ikan", "Jenis Ikan", "Harga Ikan");
    for (int i = 0; i < jmlh_ikan; i++)
    {   
        char jeniss[10];
        if(iwak[i].jenis == 0)
        {
            strcpy(jeniss, "Tawar");
        } else if(iwak[i].jenis == 1) {
            strcpy(jeniss, "Laut");
        }
        printf("%-20s %-20s %-20d\n", iwak[i].nama, jeniss, iwak[i].harga);
    }
    printf("\n\n");
    
}

// ==== VOID MENYIMPAN FILE KE CSV ==== //
void simpanKeFile(struct transaction trans[], int jmlh_trans) {
    FILE *file = fopen("C:\\Belajar_Bahasa_C\\mainTubesAlpro\\history.csv", "w");
    if (file != NULL) {
        for (int i = 0; i < jmlh_trans; i++) {
            fprintf(file, "%-20s %-20s %-20d %-20d\n", trans[i].kustomer, trans[i].nama_ikan, trans[i].jumlah, trans[i].total);
        }
        fclose(file);
        printf("Data berhasil disimpan ke dalam file.\n");
    } else {
        printf("Gagal menyimpan data ke dalam file.\n");
    }
    printf("\n\n");
}

void simpanKeFile2(struct ikan iwak[], int jmlh_ikan) {
    FILE *file2 = fopen("C:\\Belajar_Bahasa_C\\mainTubesAlpro\\history_ikan.csv", "w");
    if (file2 != NULL) {
        for (int i = 0; i < jmlh_ikan; i++) {
            char jeniss[50];
            if (iwak[i].jenis == 0)
            {
                strcpy(jeniss, "Tawar");
            } else if(iwak[i].jenis == 1) {
                strcpy(jeniss, "Laut");
            }

            fprintf(file2, "%-20s %-20s %-20d\n", iwak[i].nama, jeniss, iwak[i].harga);
        }
        fclose(file2);
        printf("Data berhasil disimpan ke dalam file.\n");
    } else {
        printf("Gagal menyimpan data ke dalam file.\n");
    }
    printf("\n\n");
}



// ==== VOID MEMUAT ATAU MEMBACA FILE CSV ==== //
void muatDariFile(struct transaction trans[], int *jmlh_trans) {
    FILE *file = fopen("C:\\Belajar_Bahasa_C\\mainTubesAlpro\\history.csv", "r");

    char nama_kustomer[max_trans][50];
    char nama_ikan[max_trans][50];
    int jumlah_ikan[max_trans], total_harga[max_trans];
    int index = *jmlh_trans;
    if (file != NULL) {
        while ((fscanf(file, "%s %s %d %d", nama_kustomer[index], nama_ikan[index], &jumlah_ikan[index], 
        &total_harga[index]) == 4) && (index < max_trans)) {
            index++;
        }

        for (int i = *jmlh_trans; i < index; i++)
        {
            strcpy(trans[*jmlh_trans].kustomer, nama_kustomer[i]);
            strcpy(trans[*jmlh_trans].nama_ikan, nama_ikan[i]);
            trans[*jmlh_trans].jumlah = jumlah_ikan[i];
            trans[*jmlh_trans].total = total_harga[i];
            (*jmlh_trans)++;
        }
        
        printf("Data berhasil dimuat dari file.\n");
    } else {
        printf("Gagal memuat data dari file.\n");
    }

    fclose(file);

    printf("\n\n");
}

// void muatDariFile(struct transaction trans[], int *jmlh_trans, struct ikan iwak[], int *jmlh_ikan) {
//     FILE *file = fopen("C:\\Belajar_Bahasa_C\\mainTubesAlpro\\history.csv", "r");

//     char nama_kustomer[max_trans][50];
//     char nama_ikan[max_trans][50];
//     int jumlah_ikan[max_trans], total_harga[max_trans];
//     int index = *jmlh_trans;
//     if (file != NULL) {
//         while ((fscanf(file, "%s %s %d %d", nama_kustomer[index], nama_ikan[index], &jumlah_ikan[index], 
//         &total_harga[index]) == 4) && (index < max_trans)) {
//             index++;
//         }
        
//         for (int i = *jmlh_trans; i < index; i++)
//         {
//             strcpy(trans[*jmlh_trans].kustomer, nama_kustomer[i]);
//             strcpy(trans[*jmlh_trans].nama_ikan, nama_ikan[i]);
//             trans[*jmlh_trans].jumlah = jumlah_ikan[i];
//             trans[*jmlh_trans].total = total_harga[i];
//             (*jmlh_trans)++;

//             // untuk memasukkan data ikan dari data yang ada pada transaction (wrong)
//             // if(*jmlh_ikan == 0) {
//             //         strcpy(iwak[*jmlh_ikan].nama, nama_ikan[i]);
//             //         iwak[*jmlh_ikan].harga = total_harga[i] / jumlah_ikan[i];
//             //         printf("Jenis ikan Tawar/Laut (0/1): \n");
//             //         scanf("%d", &iwak[*jmlh_ikan].jenis);
//             //         (*jmlh_ikan)++;
//             // } else {
//             //     for(int k = 0; k < *jmlh_ikan; k++) {
//             //         if(strcmp(iwak[k].nama, nama_ikan[i]) != 0) {
//             //             strcpy(iwak[*jmlh_ikan].nama, nama_ikan[i]);
//             //             iwak[*jmlh_ikan].harga = total_harga[i] / jumlah_ikan[i];
//             //             printf("Jenis ikan Tawar/Laut (0/1): \n");
//             //             scanf("%d", &iwak[*jmlh_ikan].jenis);
//             //             (*jmlh_ikan)++;
//             //         }
//             //     }
//             // }
//         }
        
//         printf("Data berhasil dimuat dari file.\n");
//     } else {
//         printf("Gagal memuat data dari file.\n");
//     }

//     fclose(file);

//     printf("\n\n");
// }

// Program Utama
int main() {
    struct ikan iwak[max_ikan]; // array iwak
    int jmlh_ikan = 0;

    struct transaction trans[max_trans]; // array trans
    int jmlh_trans = 0;

    int pil = 0;

    while(pil != 5) {
        printf("~~~~~~~~~~~~~~~ Aplikasi Perikanan ~~~~~~~~~~~~~~~\n\n");
        printf("       _             _   _____ _               \n");
        printf("      | |           | | |_   _| |              \n");
        printf("      | |_   _  __ _| |   | | | | ____ _ _ __  \n");
        printf("  _   | | | | |/ _` | |   | | | |/ / _` | '_ \\ \n");
        printf(" | |__| | |_| | (_| | |  _| |_|   < (_| | | | |\n");
        printf("  \\____/ \\__,_ |\\__,_|_| |_____|_|\\_\\__,_|_| |_|\n");
        printf("                                               \n");
        printf("                                               \n");
        printf("Daftar Pilih:\n");
        printf("1. Tambah Ikan\n");
        printf("2. List Ikan\n");
        if(jmlh_ikan != 0) {
            printf("3. Beli Ikan\n");
        }
        printf("4. Riwayat Transaksi\n");
        printf("5. Keluar\n");
        if(jmlh_ikan >= 2) {
            printf("- Search ikan berdasarkan Nama/jenis ikan (6/7)\n");
            printf("- Sorting berdasarkan harga termahal/harga termurah (8/9)?\n");
        }
        if (jmlh_trans >= 1)
        {
            printf("10. Simpan data transaksi ke file\n");
        }
        printf("11. Membaca data transaksi dari file\n");
        if (jmlh_ikan >= 1)
        {
         printf("12. Simpan data ikan ke file\n");   
        }
        printf("Masukkan pilihan beliau:\n");
        scanf("%d", &pil);

        switch (pil)
        {
        case 1:
            tambah_ikan(iwak, jmlh_ikan);
            jmlh_ikan++;
            break;
        
        case 2:
            list_ikan(iwak, jmlh_ikan);
            break;

        case 3:
            transaksi_ikan(iwak, jmlh_ikan, trans, &jmlh_trans);
            break;
        
        case 4:
            riwayat(trans, jmlh_trans);
            break;

        case 5:
            printf("~~~~~~~~~~~~~~~ Tengkyu Ye ~~~~~~~~~~~~~~~\n");
            break;
        
        case 6:
            search_ikan_nama(iwak, jmlh_ikan);
            break;

        case 7:
            search_jenis_ikan(iwak, jmlh_ikan);
            break;

        case 8:
            sorting_termahal(iwak, jmlh_ikan);
            break;

        case 9: 
            sorting_termurah(iwak, jmlh_ikan);
            break;

        case 10: 
            simpanKeFile(trans, jmlh_trans);
            break;

        case 11: 
            muatDariFile(trans, &jmlh_trans);
            break;

        case 12:
            simpanKeFile2(iwak, jmlh_ikan);
            break;

        default:
            printf("Pilihan tidak valid cuy!\n\n");
            break;
        }
    }

}