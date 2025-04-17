y=1;
z=10;
difference(){
    union(){
        translate([0,0,-50])
        cylinder(h=120,r=550);
        translate([0,0,1500])
        cylinder(h=100,r=550);
        difference(){
            union(){
                for (x=[0:z:1000]){
                    translate([cos(x*y)*500,sin(x*y)*500,x*1.5])
                    sphere(r=40);
                    translate([cos(x*y-180)*500,sin(x*y-180)*500,x*1.5])
                    sphere(r=40);      
                }
                cylinder(h=1520,r=520);

            }
            for (x=[0:z:1000]){
                translate([0,0,x*1.5])
                rotate([0,90,x*y+90])
                cylinder(h=1200,r=30,center=true);
            }
        }
    }
    cylinder(h=1700,r=500);
}