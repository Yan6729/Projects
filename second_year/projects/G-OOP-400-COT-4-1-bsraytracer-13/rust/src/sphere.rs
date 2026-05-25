//
// EPITECH PROJECT, 2026
// snd_year_projects
// File description:
// sphere
//

use crate::Point3D;
use crate::Ray;

pub struct Sphere {
    pub center: Point3D,
    pub radius: f32, 
}

impl Sphere {
    pub fn hits(&self, ray: Ray) -> bool {
        let origin_center = ray.origin - self.center;
        let a = ray.direction.dot(ray.direction);
        let b = 2.0 * ray.direction.dot(origin_center);
        let c = origin_center.dot(origin_center) - self.radius.powf(2.0);
        let determinant = b.powf(2.0) - (4.0 * a * c);

        if determinant >= 0.0 {
            return true;
        }
        return false;
    }
}
