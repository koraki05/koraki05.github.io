#include "FPToolkit.c"
int main() 
{
G_init_graphics(800,800) ;  
G_rgb(1, 0, 0);
//Note: if I make arrays limited to 50, the last point dissapears.
double ax_cordinate[51],ay_cordinate[51],t=0,dx_cordinate[51], dy_cordinate[51];
int i = 0,r=0,d=0;
//make the upper elipse points 
while (r < 51)
{
    t = i*M_PI/180;
    ax_cordinate[r] = 400 + 180 * cos(t);
    ay_cordinate[r] = 600 + 50 * sin(t);
    G_fill_circle(ax_cordinate[r], ay_cordinate[r], 1);
    i=i+7.6;
    r++;
}
//make the lower elipse
r = 0; i = 0; t = 0;
G_rgb(1, 0, 0);
while (r<51){
    t = i*M_PI/180;
    dx_cordinate[r] = 400 + 180 * cos(t);
    dy_cordinate[r] = 200 + 50 * sin(t);
    G_fill_circle(dx_cordinate[r], dy_cordinate[r], 1);
    i = i + 7.6;
    r++;
}
r = 0; i = 0; 

while (0 == 0) //infinite loop
{
        r = 0;
        G_rgb(1, 1, 1);
        while (r < 51) //connect r with r+i (fmod cause we dont want to go beyond 51)
        {
            int in=fmod(r+i,51);
            G_rgb(1, 0, 0);
            G_line(ax_cordinate[r], ay_cordinate[r], dx_cordinate[in], dy_cordinate[in]);
            r++;
        }
        i = i + 1;
        G_wait_key(); //press key to do the loop again
        G_rgb(1, 1, 1);
        G_clear();
}
}


