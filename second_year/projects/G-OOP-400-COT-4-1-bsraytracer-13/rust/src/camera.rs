//
// EPITECH PROJECT, 2026
// snd_year_projects
// File description:
// camera
//

use crate::Point3D;
use crate::Rectangle3D;
use crate::Ray;

pub struct Camera {
    pub origin: Point3D,
    pub screen: Rectangle3D,
}

impl Camera {
    pub fn ray(&self, u: f32, v: f32) -> Ray {
        return Ray { origin: self.origin, direction: self.screen.pointAt(u, v) - self.origin };
    }

    pub fn new(point: Point3D, rectangle: Rectangle3D) -> Self {
        return Camera { origin: point, screen: rectangle };
    }
}
