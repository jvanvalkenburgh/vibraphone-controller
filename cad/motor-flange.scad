include <BOSL2/std.scad>
include <BOSL2/screws.scad>

    shaft_thickness = 8.0;
    shaft_slack = 0.195;

    id = shaft_thickness / 2 + shaft_slack;
    od1 = shaft_thickness/2 + 1;
    od2 = od1 + 4;
    od3 = 19.5;
    thickness = 1;

module motor_flange($fn=96) {


    module shaft() {
        difference() {
            union () {
                tube(h=15, ir=id, or= id + thickness*1.5, center=false);
                tube(h=thickness*2, ir=id, or= od2, center=false);
            }
            
            translate([0,0 ,8.5]) 
                rotate([90,0,-45])
                screw_hole("M2,15",head="none",counterbore=0,anchor=CENTER);    
        }
    
    }

    module paddle() {
        difference() {

            // paddle shape
            linear_extrude(thickness) supershape(m1=4, n1=5.5,n2=12, n3=5.5, a=1.0, b=od3);

            // outer trim
            tube(h=thickness*5, ir=od3, or= od3*2, center=true);
            // cut out shaft
            tube(h=thickness*5, ir=0, or= id, center=true);

        }
    }
    
    shaft();
    paddle();
    
}


 motor_flange();

