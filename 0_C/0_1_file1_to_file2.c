/*
 * 把文本文件input.txt中的所有字母修改成另一个字母并输出到output.txt中
 * 规则：
 *      a变z, A变Z, 其余都变成它前一个字母, 大小写不变
 *
 * 例如：
 *      "An.13zyaZ" 变为 "Zm.13yxzY"
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *fp1, *fp2;
    char c1, c2;
    if((fp1 = fopen("C:\\Users\\admin\\CLionProjects\\ds_learning\\0_C\\files\\input.txt", "r")) == NULL || NULL){
        printf("不能打开input.txt！");
        // exit(0);
        return 0;
    }

    if((fp2 = fopen("C:\\Users\\admin\\CLionProjects\\ds_learning\\0_C\\files\\output.txt", "w")) == NULL || NULL){
        printf("不能打开output.txt！");
        // exit(0);
        return 0;
    }

    while((c1 = fgetc(fp1)) != EOF){    /* NOLINT */
        if(c1 == 'a' || c1 == 'A') c2 = c1 + 'z' - 'a';
        else if((c1 > 'a' && c1 <= 'z')||(c1 > 'A' && c1 <= 'Z'))
            c2 = c1 - 1;
        else
            c2 = c1;

        fputc(c2, fp2);
    }

    // 关闭两个文件
    fclose(fp1);
    fclose(fp2);

    fp1 = NULL;
    fp2 = NULL;

    return(0);
}