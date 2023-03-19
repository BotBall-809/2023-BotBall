#include <kipr/wombat.h>
#include <studio.h>

int main()
{
 creat_connect(); 
 set_create_distance(0); 
 while (get_create_distance() <1000) 
 {
     create_drive_direct(200, 200); 
 }
    create_stop () ;
    create_disconnect () ;
    return 0 ;
    {
        int main()
        {
           create_connect() ;
           set_create_total_angle(0) ;
           while (get_create_total_angle()  < 90)
           { 
               create_drive_direct(-200,200) ;
               create_stop () ;
               create_disconnect() ; 
               return 0; 
           }