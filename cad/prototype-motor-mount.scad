include <BOSL2/std.scad>

$fn = 360;

module motor() {
    
    //motor
    cylinder(h=57, r1=31/2, r2=31/2, center=false);
    // end 1
    cylinder(h=58, r1=6, r2=6, center=false);
    cylinder(h=59, r1=1.5, r2=1.5, center=false);
}

module gearbox() {
    cube([27,40,58], center= true);
    translate([0,0,58/4]) // - (13+14)])
    rotate([0,90,0]) {
    cylinder(h=36, r1=18/2, r2=18/2, center=true);
    cylinder(h=100, r1=1.5, r2=1.5, center=true);

    translate ([20,5, 0]) cylinder(h=33, r1=7.75/2, r2=7.75/2, center=true);
    translate ([20,-5, 0]) cylinder(h=33, r1=7.75/2, r2=7.75/2, center=true);

    translate ([-8,15, 0]) cylinder(h=33, r1=7.75/2, r2=7.75/2, center=true);
    translate ([-8,-15, 0]) cylinder(h=34, r1=7.75/2, r2=7.75/2, center=true);

    translate ([35,15, 0]) cylinder(h=33, r1=7.75/2, r2=7.75/2, center=true);
    translate ([35,-15, 0]) cylinder(h=33, r1=7.75/2, r2=7.75/2, center=true);
    
   // translate ([35-7.75/2,10, 0]) cylinder(h=35, r1=7.75/2, r2=7.75/2, center=true);
   // translate ([35-7.75/3,11, 0]) cylinder(h=35, r1=7.75/2, r2=7.75/2, center=true);
   // translate ([35-7.75/4,12, 0]) cylinder(h=35, r1=7.75/2, r2=7.75/2, center=true);
    }

}

module motor_assembly() {
    gearbox();
    translate ([3,0,-58/2]) rotate([0,180,0]) motor();

}


module mount_frame() {

    base_z = -30;
    difference () {
        // inner
        translate ([0,0,base_z]) cube([42+2,40+2,118+2], center= true);
        translate ([0,0,base_z-2]) cube([42,40,118], center= true);
    }
}

//difference () {

    mount_frame();
    motor_assembly();
//}
