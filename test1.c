#include <stdio.h>
#include <string.h>


typedef struct {
    int id;
    char name[20];
    int age;
} Student;

// 功能项1：从键盘输入学生信息并存入结构数组
void input_students(Student students[], int n) {
    int i = 0;
	for (; i < n; i++) {
        printf("请输入第%d位学生的学号、姓名和年龄（用空格隔开）：", i + 1);
        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].age);
    }
}

// 功能项2：将结构数组中的数据保存到文件中
void save_to_file(const Student students[], int n, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("无法打开文件 %s", filename);
        return;
    }
    int i = 0;
	for (; i < n; i++) {
        fwrite(&students[i], sizeof(Student), 1, file);
    }
    fclose(file);
}

// 功能项3：从文件中读取数据并反向顺序输出到另一个文件
void reverse_output_to_file(const char *input_filename, const char *output_filename, int n) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("无法打开文件 %s", input_filename);
        return;
    }
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("无法打开文件 %s", output_filename);
        fclose(input_file);
        return;
    }
    Student temp;
    int i = 0;
    for (; i < n; i++) {
        fread(&temp, sizeof(Student), 1, input_file);
        fwrite(&temp, sizeof(Student), 1, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

int main() {
    const int n = 5;
    Student students[n];
    input_students(students, n);
    save_to_file(students, n, "input.dat");
    reverse_output_to_file("input.dat", "output.dat", n);
    return 0;
}
