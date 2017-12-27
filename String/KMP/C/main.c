#include <stdio.h>
#include <stdlib.h>

//m,n分别为字符串和匹配字符串的长度
int m = 0,n = 0;
/**
 * 获取匹配字符串的next数组
 * @param string
 * @param length
 * @param next
 */
void get_next(char *string, int length,int *next)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < length){
        if(j == 0 || string[i] == string[j]){
            j++;
            i++;
            if(string[i] == string[j])
                next[i] = j; //回溯
            else next[i] = next[j];
        }
        else j = next[j];
    }
}

/**
 * 获取字符串的长度
 * @param length
 * @param string
 */
void get_length(int *length, char *string)
{
    while(*string != '\0'){
        (*length)++;
        string++;
    }
}


void main()
{
    char string[255], match[255];
    int next[255], i = 0, j =0;

    //字符串
    printf("Input the string\n");
    scanf("%s",string);
    //匹配的字符串
    printf("Input the mathing string\n");
    scanf("%s",match);

    //分别获取字符串和匹配字符串的长度
    get_length(&m,string);
    get_length(&n,match);

    //匹配字符串的next数组
    get_next(match,n,next);

    while (i < m && j < n){
        if(j==0 || string[i] == match[j]){
            i++;
            j++;
        }
        else j = next[j];
    }

    if(j >= n) printf("%d\n",(i - j + 1));
    else printf("%d\n", 0);
}

