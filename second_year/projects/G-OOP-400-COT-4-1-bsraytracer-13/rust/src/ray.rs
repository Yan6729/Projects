//
// EPITECH PROJECT, 2026
// snd_year_projects
// File description:
// ray
//

use crate::Vector3D;
use crate::Point3D;

#[derive(Debug, Clone, Copy)]
pub struct Ray {
    pub origin: Point3D,
    pub direction: Vector3D,
}

impl Ray {
    pub fn new(point: Point3D, vector: Vector3D) -> Ray {
        return Ray { origin: point, direction: vector };
    }
}
