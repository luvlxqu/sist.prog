#include <stdio.h>
#include <string.h>
 
char tracks [] [80] ={
    "Я оставил сердце в медицинской школе",
    "Нью-Йорк, Нью-Йорк- город, полный чудес",
    "Танец с мужланом",
    "Отсюда и до роддома",
    "Девчонка с острова Иводзима",
};
 void find_track (char search_for[]){
    int i;
    for (i=0; i<5; i++)
    {
        if(strstr(tracks[i], search_for))
        printf("Песня номер %i: '%s'\n",i,tracks[i]);
    }
 }

 int main ()
 {
    char search_for[80];
    printf("Искать:");
    fgets(search_for,80,stdin);
    search_for[strlen(search_for)-1]= '\0';
    find_track(search_for);
    return 0;

    
 }