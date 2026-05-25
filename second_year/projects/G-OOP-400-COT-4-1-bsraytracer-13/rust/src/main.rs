//use std::ops;
mod vector3d;
mod point3d;
mod ray;
mod sphere;
mod rectangle3d;
mod camera;

use std::env;
use crate::point3d::Point3D;
use crate::vector3d::Vector3D;
use crate::ray::Ray;
use crate::sphere::Sphere;
use crate::rectangle3d::Rectangle3D;
use crate::camera::Camera;

fn write_color(color: Vector3D)
{
    println!("{} {} {}", color.x, color.y, color.z);
}

fn main()
{
    let height: u32;
    let width: u32;
    let args: Vec<String> = env::args().collect();
    let rectangle = Rectangle3D {
        origin: Point3D { x: -1.0, y: -1.0, z: -1.0 },
        left_side: Vector3D { x: 0.0, y: 2.0, z: 0.0 },
        bottom_side: Vector3D { x: 2.0, y: 0.0, z: 0.0 },
    };
    let cam = Camera::new(Point3D { x: 0.0, y: 0.0, z: 0.0 }, rectangle);
    let _sp = Sphere {
        center: Point3D { x: 0.0, y: 0.0, z: -1.0 },
        radius: 0.5,
    };

    if args.len() == 3 {
        width = args[1].parse().unwrap();
        height = args[2].parse().unwrap();
    } else {
        width = 600;
        height = 400;
    }

    println!("P3\n {} {} \n255", width, height);
    for h in (1..height+1).rev() {
        for w in 1..width+1 {
            let u: f32 = (w as f32) / (width as f32);
            let v: f32 = (h as f32) / (height as f32);
            let _ray = cam.ray(u, v);
            
            if _sp.hits(_ray) == true {
                write_color(Vector3D { x: (w / 255) as f32, y: (h / 255) as f32, z: 240.0 });
            } else {
                write_color(Vector3D { x: 255.0, y: 255.0, z: 255.0 });
            }
        }
        println!("");
    }
}