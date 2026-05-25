//
// EPITECH PROJECT, 2026
// snd_year_projects
// File description:
// point3D
//

use crate::Vector3D;
use std::ops;

#[derive(Debug, Clone, Copy)]
pub struct Point3D {
    pub x: f32,
    pub y: f32,
    pub z: f32,
}

impl ops::Add<Vector3D> for Point3D {
    type Output = Point3D;

    fn add(self, vector: Vector3D) -> Point3D {
        return Point3D { x: (self.x + vector.x), y: (self.y + vector.y), z: (self.z + vector.z) };
    }
}

impl ops::AddAssign<Vector3D> for Point3D {
    
    fn add_assign(&mut self, vector: Vector3D) {
        let result = *self + vector;
        *self = result;
    }
}

impl ops::Sub<Point3D> for Point3D {
    type Output = Vector3D;

    fn sub(self, other: Point3D) -> Vector3D {
        return Vector3D { x: (self.x - other.x), y: (self.y - other.y), z: (self.z - other.z) };
    }
}
