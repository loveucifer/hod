#ifndef HOD_H
#define HOD_H

#include "math.h"

#define swap(a, b) _Generic(a, \
    int*: int_swap, \
    float*: float_swap \
)(a, b)

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
    float length = vec2_len(*v);
    if(length == 0.0f) return;
    v->x /= length;
    v->y /= length;
}

static inline Vec2_t vec2_new(float x, float y){
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


static Vec3_t vec3_new(float x, float y, float z){
    Vec3_t result = {x,y,z};
    return result;
}

static Vec3_t vec3_clone(Vec3_t *v){
   Vec3_t result = {v->x , v->y, v->z};
   return  result;
}

static float vec3_len(Vec3_t v){
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
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
    float length = vec3_len(*v);
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

/*///////////////////////////////////////////////
////// VECTOR CONVERSIONS////////////////////////
//////////////////////////////////////////////*/


static Vec4_t vec4_from_vec3(Vec3_t v){
    Vec4_t result = {v.x , v.y , v.z, 1.0};
    return result;
}

static Vec3_t vec3_from_vec4(Vec4_t v){
    Vec3_t result = {v.x , v.y , v.z};
    return result;
}

static Vec2_t vec2_from_vec4(Vec4_t v){
    Vec2_t result = {v.x , v.y};
    return result;
}


////////////////////////////////////////////////
///////// MATRIX FUNCTIONS /////////////////////
////////////////////////////////////////////////

typedef struct{

    float m[4][4];

} mat4_t;


static mat4_t mat4_identity(void){

    mat4_t m = {{
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    }};
    return m;
}


static mat4_t mat4_scale(float sx , float sy , float sz){
    // sx 0 0 0
    // 0 sy 0 0
    // 0 0 sz 0
    // 0 0 0  1
    mat4_t m = mat4_identity();
    m.m[0][0] = sx;
    m.m[1][1] = sy;
    m.m[2][2] = sz;

    return m;
}

static mat4_t  mat4_translaton(float tx , float ty , float tz ){

    mat4_t m = mat4_identity();
       m.m[0][3] = tx;
       m.m[1][3] = ty;
       m.m[2][3] = tz;


    return m;
}

/////////////////////////////////////////////
//////// rotation //////////////////////////
///////////////////////////////////////////



static mat4_t  mat4_rotation_x (float angle){
    float c = cos(angle);
    float s = sin(angle);

    mat4_t m = mat4_identity();
    m.m[1][1] = c;
    m.m[1][2] = -s;
    m.m[2][1] = s;
    m.m[2][2] = c;
    return m;
}

static mat4_t  mat4_rotation_y (float angle ){
    float c = cos(angle);
    float s = sin(angle);

    mat4_t m = mat4_identity();
    m.m[0][0] = c;
    m.m[0][2] = s;
    m.m[2][0] = -s;
    m.m[2][2] = c;
    return m;
}

static mat4_t  mat4_rotation_z (float angle ){
    float c = cos(angle);
    float s = sin(angle);

    mat4_t m = mat4_identity();
    m.m[0][0] = c;
    m.m[0][1] = -s;
    m.m[1][0] = s;
    m.m[1][1] = c;
    return m;
}


static Vec4_t  mat4_mul_vec4(mat4_t m, Vec4_t v){
    Vec4_t  result;
    result.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3] * v.w ;
    result.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3] * v.w ;
    result.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3] * v.w ;
    result.w = m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + m.m[3][3] * v.w ;
    return result;
}

static mat4_t  mat4_t_mul_mat4(mat4_t a, mat4_t b){
    mat4_t m;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4 ; j++) {
            m.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m [1][j] + a.m[i][2] * b.m [2][j] + a.m[i][3] * b.m[3][j];
        }

    }
    return m;
}

static mat4_t mat4_perspective(float fov, float aspect , float znear , float zfar ){
    mat4_t m = {{{0}}};
    m.m[0][0] = aspect * (1/tan(fov/2));
    m.m[1][1] = 1/ tan (fov / 2);
    m.m[2][2] = zfar / (zfar - znear);
    m.m[2][3] = (-zfar * znear)/ (zfar - znear);
    m.m[3][2] = 1.0;

    return m;

}

static Vec4_t mat4_t_mul_vec4_t(mat4_t mat_proj , Vec4_t v ){
    Vec4_t result = mat4_mul_vec4(mat_proj,  v);

    if (result.w != 0.0) {
        result.x /= result.w;
        result.y /= result.w;
        result.z /= result.w;

    }
    return result;
}


static mat4_t mat4_look_at(Vec3_t eye, Vec3_t target, Vec3_t up) {
    // Compute the forward (z), right (x), and up (y) vectors
    Vec3_t z = vec3_sub(target, eye);
    vec3_normalize(&z);
    Vec3_t x = vec3_cross(up, z);
    vec3_normalize(&x);
    Vec3_t y = vec3_cross(z, x);

    // | x.x   x.y   x.z  -dot(x,eye) |
    // | y.x   y.y   y.z  -dot(y,eye) |
    // | z.x   z.y   z.z  -dot(z,eye) |
    // |   0     0     0            1 |
    mat4_t view_matrix = {{
        { x.x, x.y, x.z, -vec3_dot(x, eye) },
        { y.x, y.y, y.z, -vec3_dot(y, eye) },
        { z.x, z.y, z.z, -vec3_dot(z, eye) },
        {   0,   0,   0,                 1 }
    }};
    return view_matrix;
}

///////////////////////////////////////
/// swap functions ////////////////////
///////////////////////////////////////

static void int_swap(int* a , int* b ){
    int temp = *a;
    *a = *b;
    *b = temp;

}

static void float_swap(float* a , float* b ){
    float temp = *a;
    *a = *b;
    *b = temp;

}


// interpolation

static float float_lerp(float a, float b , float t){
    return  a + t * (b - a);     /// interpolation formula
}



//// baycentric weights ///

static Vec3_t barycentric_weights(Vec2_t a, Vec2_t b, Vec2_t c, Vec2_t p) {
    // Find the vectors between the vertices ABC and point p
    Vec2_t ac = vec2_sub(c, a);
    Vec2_t ab = vec2_sub(b, a);
    Vec2_t ap = vec2_sub(p, a);
    Vec2_t pc = vec2_sub(c, p);
    Vec2_t pb = vec2_sub(b, p);

    // Compute the area of the full parallegram/triangle ABC using 2D cross product
    float area_parallelogram_abc = (ac.x * ab.y - ac.y * ab.x); // || AC x AB ||

    // Alpha is the area of the small parallelogram/triangle PBC divided by the area of the full parallelogram/triangle ABC
    float alpha = (pc.x * pb.y - pc.y * pb.x) / area_parallelogram_abc;

    // Beta is the area of the small parallelogram/triangle APC divided by the area of the full parallelogram/triangle ABC
    float beta = (ac.x * ap.y - ac.y * ap.x) / area_parallelogram_abc;

    // Weight gamma is easily found since barycentric coordinates always add up to 1.0
    float gamma = 1 - alpha - beta;

    Vec3_t weights = { alpha, beta, gamma };
    return weights;
}


#endif
