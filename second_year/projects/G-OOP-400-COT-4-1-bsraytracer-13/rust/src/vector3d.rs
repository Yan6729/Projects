//
// EPITECH PROJECT, 2026
// snd_year_projects
// File description:
// vector3D
//

use std::ops;

#[derive(Debug, Clone, Copy)]
pub struct Vector3D {
    pub x: f32,
    pub y: f32,
    pub z: f32,
}

impl Vector3D {
    pub fn length(&self) -> f32 {
        return (self.x.powf(2.0) + self.y.powf(2.0) + self.z.powf(2.0)).sqrt();
    }

    pub fn dot(&self, other: Self) -> f32 {
        return (self.x * other.x) + (self.y * other.y) + (self.z * other.z);
    }
}

impl ops::Add<Vector3D> for Vector3D {
    type Output = Vector3D;

    fn add(self, other: Vector3D) -> Vector3D {
        return Vector3D { x: self.x + other.x, y: self.y + other.y, z: self.z + other.z };
    }
}

impl ops::Sub<Vector3D> for Vector3D {
   type Output = Vector3D;

    fn sub(self, other: Vector3D) -> Vector3D {
        return Vector3D { x: self.x - other.x, y: self.y - other.y, z: self.z - other.z };
    }
}

impl ops::Div<Vector3D> for Vector3D {
    type Output = Vector3D;

    fn div(self, other: Vector3D) -> Vector3D {
        let x: f32;
        let y: f32;
        let z: f32;

        x = if other.x == 0.0 { 0.0 } else { self.x / other.x };
        y = if other.y == 0.0 { 0.0 } else { self.y / other.y };
        z = if other.z == 0.0 { 0.0 } else { self.z / other.z };
        return Vector3D { x: x, y: y, z: z };
    }
}

impl ops::Mul<Vector3D> for Vector3D {
    type Output = Vector3D;

    fn mul(self, other: Vector3D) -> Vector3D {
        return Vector3D { x: (self.x * other.x), y: (self.z * other.y), z: (self.x * other.z) };
    }
}

impl ops::AddAssign<Vector3D> for Vector3D {

    fn add_assign(&mut self, other: Vector3D) {
        let result = *self + other;
        *self = result;
    }
}

impl ops::SubAssign<Vector3D> for Vector3D {

    fn sub_assign(&mut self, other: Vector3D) {
        let result = *self - other;
        *self = result;
    }
}

impl ops::MulAssign<Vector3D> for Vector3D {

    fn mul_assign(&mut self, other: Vector3D) {
        let result = *self * other;
        *self = result;
    }
}

impl ops::DivAssign<Vector3D> for Vector3D {

    fn div_assign(&mut self, other: Vector3D) {
        let result = *self / other;
        *self = result;
    }
}

impl ops::Mul<f32> for Vector3D {
    type Output = Vector3D;

    fn mul(self, value: f32) -> Vector3D {
        return Vector3D { x: self.x * value, y: self.y * value, z: self.z * value };
    }
}

impl ops::MulAssign<f32> for Vector3D {

    fn mul_assign(&mut self, value: f32) {
        let result = *self * value;
        *self = result;
    }
}

impl ops::Div<f32> for Vector3D {
    type Output = Vector3D;

    fn div(self, value: f32) -> Vector3D {
        return self * (1.0 / value);
    }
}

impl ops::DivAssign<f32> for Vector3D {

    fn div_assign(&mut self, value: f32) {
        let result = *self / value;
        *self = result;
    }
}
