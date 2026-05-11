#ifndef HOD_H
#define HOD_H

#include "math.h"

/////////////////////////////
///// Vectors ///////////////
/////////////////////////////

typedef struct{
    float x;
    float y;
} Vec2_t;

typedef struct{
    float x;
    float y;
    float z;
} Vec3_t;

typedef struct{
    float x;
    float y;
    float z;
    float w;
} Vec4_t;


////////////////////////////////
// 2D VECTOR functions /////////
////////////////////////////////

static inline float vec2_len(Vec2_t v){
    return sqrtf(v.x * v.x + v.y * v.y );
}

static inline Vec2_t vec2_add(Vec2_t a, Vec2_t b){
    Vec2_t result = {
        .x = a.x + b.x,
        .y = a.y + b.y
    };
    return result;
}

static inline Vec2_t vec2_sub(Vec2_t a, Vec2_t b){
    Vec2_t result = {
        .x = a.x - b.x,
        .y = a.y - b.y
    };
    return result;
}

static inline Vec2_t vec2_mul(Vec2_t v, float factor){
    Vec2_t result = {
        .x = v.x * factor,
        .y = v.y * factor
    };
    return result;
}

static inline Vec2_t vec2_div(Vec2_t v, float factor){
    Vec2_t result = {
        .x = v.x / factor,
        .y = v.y / factor
    };
    return result;
}

static inline float vec2_dot(Vec2_t a, Vec2_t b){
    return ( a.x * b.x) + (a.y * b.y);
}

static inline void vec2_normalize(Vec2_t *v){
    float length = sqrt(v->x * v->x + v->y * v->y );
    v->x /= length;
    v->y /= length;
}

static inline Vec2_t vec2_new(float x,  float y){
    Vec2_t result = {x,y};
    return result;
}

static inline Vec2_t vec2_clone(Vec2_t *v){
   Vec2_t result = {v->x , v->y};
   return  result;
}


/////////////////////////////////////
//// 3D Vector //////////////////////
/////////////////////////////////////


static Vec3_t vec3_new(float x,  float y,float z){
    Vec3_t result = {x,y,z};
    return result;
}

static Vec3_t vec3_clone(Vec3_t *v){
   Vec3_t result = {v->x , v->y, v->z};
   return  result;
}

static float vec3_len(Vec3_t v){
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
};

static Vec3_t vec3_add(Vec3_t a, Vec3_t b) {
  Vec3_t result = {
      .x = a.x + b.x,
      .y = a.y + b.y,
      .z = a.z + b.z
  };
  return result;
}

static Vec3_t vec3_sub(Vec3_t a, Vec3_t b) {
  Vec3_t result = {
      .x = a.x - b.x,
      .y = a.y - b.y,
      .z = a.z - b.z
  };
  return result;
}

static Vec3_t vec3_mul(Vec3_t v, float factor){
  Vec3_t result = {
      .x = v.x * factor,
      .y = v.y * factor,
      .z = v.z *factor
  };
  return result;
}

static Vec3_t vec3_div(Vec3_t v, float factor) {
  Vec3_t result = {
      .x = v.x / factor,
      .y = v.y / factor,
      .z = v.z / factor
  };
  return result;
}

static Vec3_t vec3_cross(Vec3_t a, Vec3_t b){
    Vec3_t result = {
        .x = a.y * b.z - a.z * b.y,
        .y = a.z * b.x - a.x * b.z,
        .z = a.x * b.y - a.y * b.x
    };
    return result;
}

static float vec3_dot(Vec3_t a, Vec3_t b){
    return ( a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}


static void vec3_normalize(Vec3_t *v){
    float length = sqrt(v->x * v->x + v->y * v->y +  v->z * v->z );
    if (length == 0.0f) return;
    v->x /= length;
    v->y /= length;
    v->z /= length;
}

static Vec3_t Vec3_rotate_x(Vec3_t v, float angle) {
  Vec3_t rotated_vector = {.x = v.x,
                           .y = v.y * cos(angle) - v.z * sin(angle),
                           .z = v.y * sin(angle) + v.z * cos(angle)};
  return rotated_vector;
}

static Vec3_t Vec3_rotate_y(Vec3_t v, float angle) {
  Vec3_t rotated_vector = {.x = v.x * cos(angle) - v.z * sin(angle),
                           .y = v.y,
                           .z = v.x * sin(angle) + v.z * cos(angle)};
  return rotated_vector;
}

static Vec3_t Vec3_rotate_z(Vec3_t v, float angle) {
  Vec3_t rotated_vector = {.x = v.x * cos(angle) - v.y * sin(angle),
                           .y = v.x * sin(angle) + v.y * cos(angle),
                           .z = v.z};
  return rotated_vector;
}





#endif
