#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int nrp;
  char nama[30];
  float eval1;
  float eval2;
  float eval3;
  float uas;
  float rata;
  float maks;
  float min;
  char grade[2];
} Mahasiswa;

int menu();
void tambah_mahasiswa(Mahasiswa *, int, int *);
void tampil_mahasiswa(Mahasiswa *, int *);
float hitung_max(float, float);
float hitung_min(float, float);
void hitung_grade(char *, float);

void main()
{
  printf("Selamat Datang di Program Nilai Mahasiswa\nOleh Indra Rahmat Maulidi NRP 3124600017\n");

  int loop = 0;
  do
  {
    loop = menu();
  } while (loop != 0);
}

static int m = 0;

int menu()
{
  int pil, n = 4;

  Mahasiswa data_mahasiswa[n];

  // // Database Mahasiswa
  // // index 0
  // data_mahasiswa[0].nrp = 21101;
  // strcpy(data_mahasiswa[0].nama, "Adi");
  // data_mahasiswa[0].eval1 = 80;
  // data_mahasiswa[0].eval2 = 85;
  // data_mahasiswa[0].eval3 = 90;
  // data_mahasiswa[0].uas = 80;
  // data_mahasiswa[0].rata = 83.75;
  // data_mahasiswa[0].maks = 90;
  // data_mahasiswa[0].min = 80;
  // strcpy(data_mahasiswa[0].grade, "A-");
  // // index 1
  // data_mahasiswa[1].nrp = 21102;
  // strcpy(data_mahasiswa[1].nama, "Budi");
  // data_mahasiswa[1].eval1 = 90;
  // data_mahasiswa[1].eval2 = 75;
  // data_mahasiswa[1].eval3 = 83;
  // data_mahasiswa[1].uas = 86;
  // data_mahasiswa[1].rata = 83.5;
  // data_mahasiswa[1].maks = 90;
  // data_mahasiswa[1].min = 75;
  // strcpy(data_mahasiswa[1].grade, "A-");
  // // index 2
  // data_mahasiswa[2].nrp = 21103;
  // strcpy(data_mahasiswa[2].nama, "Ani");
  // data_mahasiswa[2].eval1 = 70;
  // data_mahasiswa[2].eval2 = 73;
  // data_mahasiswa[2].eval3 = 78;
  // data_mahasiswa[2].uas = 80;
  // data_mahasiswa[2].rata = 75.25;
  // data_mahasiswa[2].maks = 80;
  // data_mahasiswa[2].min = 70;
  // strcpy(data_mahasiswa[2].grade, "B+");
  // // Sementara buat debugging
  // // Include ke Database
  // m = 3;

  printf("\nSilahkan pilih menu anda:\n1. Menambahkan mahasiswa dan nilai\n2. Menampilkan Data Mahasiswa\n3. Selesai\n");
  printf("Pilihan anda: ");
  scanf("%d", &pil);

  if (pil == 1)
    tambah_mahasiswa(data_mahasiswa, n, &m);
  else if (pil == 2)
    tampil_mahasiswa(data_mahasiswa, &m);
  else
    return 0;

  return 1;
}

void tambah_mahasiswa(Mahasiswa *data, int n, int *m)
{
  char loop = 'y';
  while (*m < n - 1 && (loop == 'y' || loop == 'Y'))
  {
    printf("\nData mahasiswa ke-%d\n", *m + 1);
    printf("NRP\t\t\t\t: ");
    if (scanf("%d", &data[*m].nrp) != 1)
    {
      printf("Input NRP tidak valid!\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    while (getchar() != '\n')
      ; // Bersih buffer

    printf("Nama\t\t\t\t: ");
    fgets(data[*m].nama, sizeof(data[*m].nama), stdin);
    data[*m].nama[strcspn(data[*m].nama, "\n")] = '\0';

    printf("Nilai (Eval1 Eval2 Eval3 UAS)\t: ");
    if (scanf("%f %f %f %f", &data[*m].eval1, &data[*m].eval2, &data[*m].eval3, &data[*m].uas) != 4)
    {
      printf("Input nilai tidak valid!\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    (*m + data)->rata = ((*m + data)->eval1 + (*m + data)->eval2 + (*m + data)->eval3 + (*m + data)->uas) / 4;

    (*m + data)->maks = hitung_max(hitung_max((*m + data)->eval1, (*m + data)->eval2), hitung_max((*m + data)->eval3, (*m + data)->uas));

    (*m + data)->min = hitung_min(hitung_min((*m + data)->eval1, (*m + data)->eval2), hitung_min((*m + data)->eval3, (*m + data)->uas));

    hitung_grade((*m + data)->grade, (*m + data)->rata);

    (*m)++;
    printf("Mau menambahkan lagi? (y/t) : ");
    scanf(" %c", &loop);
  }

  if (*m >= n - 1 && (loop == 'y' || loop == 'Y'))
    printf("Error!!!\nData sudah penuh!!!\n");
  return;
}

void tampil_mahasiswa(Mahasiswa *data, int *m)
{
  if (*m == 0)
  {
    printf("Belum ada data yang diinputkan\n");
    return;
  }
  float rata_seluruh = 0;

  float nilai_tertinggi = 0, nilai_terendah = 999;
  int id_max_nilai, id_min_nilai;

  float eval1_maks = 0, eval1_min = 999;
  int id_max_eval1, id_min_eval1;

  float eval2_maks = 0, eval2_min = 999;
  int id_max_eval2, id_min_eval2;

  float eval3_maks = 0, eval3_min = 999;
  int id_max_eval3, id_min_eval3;

  float uas_maks = 0, uas_min = 999;
  int id_max_uas, id_min_uas;

  printf("=====================================================================================================================\n");
  printf("No\tNRP\t%-30s Eval1\tEval2\tEval3\tUAS\tRata-rata\tMaks\tmin\tGrade\n", "Nama");
  printf("=====================================================================================================================\n");

  for (int i = 0; i < *m; i++)
  {
    printf("%d\t%d\t%-30s %.f\t%.f\t%.f\t%.f\t%.2f\t\t%.f\t%.f\t%s\n", i + 1, (i + data)->nrp, (i + data)->nama, (i + data)->eval1, (i + data)->eval2, (i + data)->eval3, (i + data)->uas, (i + data)->rata, (i + data)->maks, (i + data)->min, (i + data)->grade);

    rata_seluruh += (i + data)->rata;

    nilai_tertinggi = hitung_max(nilai_tertinggi, (i + data)->rata);
    if (nilai_tertinggi == (i + data)->rata)
      id_max_nilai = i;
    nilai_terendah = hitung_min(nilai_terendah, (i + data)->rata);
    if (nilai_terendah == (i + data)->rata)
      id_min_nilai = i;

    eval1_maks = hitung_max(eval1_maks, (i + data)->eval1);
    if (eval1_maks == (i + data)->eval1)
      id_max_eval1 = i;
    eval1_min = hitung_min(eval1_min, (i + data)->eval1);
    if (eval1_min == (i + data)->eval1)
      id_min_eval1 = i;

    eval2_maks = hitung_max(eval2_maks, (i + data)->eval2);
    if (eval2_maks == (i + data)->eval2)
      id_max_eval2 = i;
    eval2_min = hitung_min(eval2_min, (i + data)->eval2);
    if (eval2_min == (i + data)->eval2)
      id_min_eval2 = i;

    eval3_maks = hitung_max(eval3_maks, (i + data)->eval3);
    if (eval3_maks == (i + data)->eval3)
      id_max_eval3 = i;
    eval3_min = hitung_min(eval3_min, (i + data)->eval3);
    if (eval3_min == (i + data)->eval3)
      id_min_eval3 = i;

    uas_maks = hitung_max(uas_maks, (i + data)->uas);
    if (uas_maks == (i + data)->uas)
      id_max_uas = i;
    uas_min = hitung_min(uas_min, (i + data)->uas);
    if (uas_min == (i + data)->uas)
      id_min_uas = i;
  }

  rata_seluruh /= *m;

  printf("=====================================================================================================================\n");
  printf("\n");
  printf("Nilai rata-rata seluruh mahasiswa : %.2f\n", rata_seluruh);
  printf("Nilai Mahasiswa tertinggi : %s dengan nilai %.2f\n", (id_max_nilai + data)->nama, (id_max_nilai + data)->rata);
  printf("Nilai Mahasiswa terendah : %s dengan nilai %.2f\n", (id_min_nilai + data)->nama, (id_min_nilai + data)->rata);
  printf("Nilai Mahasiswa dengan Eval1 tertinggi: %s dengan nilai %.0f\n", (id_max_eval1 + data)->nama, (id_max_eval1 + data)->eval1);
  printf("Nilai Mahasiswa dengan Eval1 terendah: %s dengan nilai %.0f\n", (id_min_eval1 + data)->nama, (id_min_eval1 + data)->eval1);
  printf("Nilai Mahasiswa dengan Eval2 tertinggi: %s dengan nilai %.0f\n", (id_max_eval2 + data)->nama, (id_max_eval2 + data)->eval2);
  printf("Nilai Mahasiswa dengan Eval2 terendah: %s dengan nilai %.0f\n", (id_min_eval2 + data)->nama, (id_min_eval2 + data)->eval2);
  printf("Nilai Mahasiswa dengan Eval3 tertinggi: %s dengan nilai %.0f\n", (id_max_eval3 + data)->nama, (id_max_eval3 + data)->eval3);
  printf("Nilai Mahasiswa dengan Eval3 terendah: %s dengan nilai %.0f\n", (id_min_eval3 + data)->nama, (id_min_eval3 + data)->eval3);
  printf("Nilai Mahasiswa dengan UAS tertinggi: %s dengan nilai %.0f\n", (id_max_uas + data)->nama, (id_max_uas + data)->uas);
  printf("Nilai Mahasiswa dengan UAS terendah: %s dengan nilai %.0f\n", (id_min_uas + data)->nama, (id_min_uas + data)->uas);

  printf("\nKembali ke menu utama ( masukkan huruf apapun ) => \n");
  system("pause");
}

float hitung_max(float x, float y)
{
  if (x > y)
    return x;

  return y;
}

float hitung_min(float x, float y)
{
  if (x < y)
    return x;

  return y;
}

void hitung_grade(char *grade, float rata)
{
  if (rata >= 86)
  {
    strcpy(grade, "A ");
    return;
  }
  if (rata >= 81)
  {
    strcpy(grade, "A-");
    return;
  }
  if (rata >= 76)
  {
    strcpy(grade, "AB");
    return;
  }
  if (rata >= 71)
  {
    strcpy(grade, "B+");
    return;
  }
  if (rata >= 66)
  {
    strcpy(grade, "B ");
    return;
  }
  if (rata >= 61)
  {
    strcpy(grade, "BC");
    return;
  }
  if (rata >= 56)
  {
    strcpy(grade, "C ");
    return;
  }
  if (rata >= 41)
  {
    strcpy(grade, "D ");
    return;
  }
  if (rata < 41)
  {
    strcpy(grade, "E ");
    return;
  }
}
