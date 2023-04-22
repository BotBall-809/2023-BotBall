#include <kipr/wombat.h>
#include <kipr/create.h>

void forward(int mm)
{

    set_create_distance(0);
    while (get_create_distance() <mm)
    {
    create_drive_direct(150,150);
    }
    create_stop();
    
}

void backward(int mm)
{

	       set_create_distance(0);
    while (get_create_distance() > -mm) 
    {
    create_drive_direct(-150,-150);
    }
    create_stop();
    
}

void turn_left(int degrees)
{
set_create_total_angle(0);
while (get_create_total_angle() <degrees)
{
create_drive_direct(-150,150);
}
    create_stop();
}

void turn_right(degrees)
{
set_create_total_angle(0);
while (get_create_total_angle() > -degrees)
{
create_drive_direct(150,-150);
}
    create_stop();
}

void line_follow_till_bump()
{
	int black = 600;
	int white = 2500;
    int speed = 200;
    
    while(get_create_rbump()==0)
    {
    int actual = get_create_rfcliff_amt();
    if(actual<black)
    {black=actual;}
    if (actual>white)
    {white=actual;}
    double target = (black+white)/2;
        
    double deviation =(abs(actual-target))/target*0.5;
        int increase_to_speed=speed*(1+deviation);
        
        if(actual<target)
        {
        create_drive_direct(speed,increase_to_speed);
        }
       else 
       {
       create_drive_direct(increase_to_speed,speed);
       }
           
            }
}
int main()
 {
    create_connect();

    forward(100);
    turn_left(90);
    turn_right(90);
    backward(100);
    line_follow_till_bump();
    create_disconnect();
    return 0;
}
