//
// EPITECH PROJECT, 2026
// snd_year_projects
// File description:
// rectangle3D
//

use crate::Vector3D;
use crate::Point3D;

pub struct Rectangle3D {
    pub origin: Point3D,
    pub left_side: Vector3D,
    pub bottom_side: Vector3D,
}

impl Rectangle3D {
    pub fn pointAt(&self, u: f32, v: f32) -> Point3D {
        return self.origin + (self.bottom_side * u) + (self.left_side * v);
    }
}
