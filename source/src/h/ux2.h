/*
** ux2.h | The Sol Vector Library | Code for u32x2 and u64x2.
** https://github.com/davidgarland/sol
*/

#ifndef SOL_UX2_H
#define SOL_UX2_H

#ifdef SOL_GNU
  #define UX2_OP(A, OP, B) A OP B
  #define UX2_OPF(V, OP, F) V OP F
  #define UX2_FOP(F, OP, V) F OP V
  #define UX2_OP2(A, AB, B, BC, C) (A AB B) BC C
#else
  #define UX2_OP(A, OP, B) {x(A) OP x(B), y(A) OP y(B)}
  #define UX2_OPF(V, OP, F) {x(V) OP F, y(V) OP F}
  #define UX2_FOP(F, OP, V) {F OP x(V), F OP y(V)}
  #define UX2_OP2(A, AB, B, BC, C) {(x(A) AB x(B)) BC x(C), (y(A) AB y(B)) BC y(C)}
#endif

#define UX2(T, V) \
\
/* Initializers */ \
\
_sol_ \
V V##_set(T x, T y) {   \
  const V out = {x, y}; \
  return out;           \
}                       \
\
_sol_ \
V V##_setf(T f) {       \
  return V##_set(f, f); \
} \
\
_sol_ \
V V##_zero(void) {    \
  return V##_setf(0); \
} \
\
/* Basic Math */ \
\
_sol_ \
T V##_sum(V v) {      \
  return x(v) + y(v); \
}                     \
\
_sol_ \
V V##_sq(V v) {         \
  return V##_mul(v, v); \
}                       \
\
_sol_ \
V V##_add(V a, V b) {            \
  const V out = UX2_OP(a, +, b); \
  return out;                    \
}                                \
\
_sol_ \
V V##_addf(V v, T f) {            \
  const V out = UX2_OPF(v, +, f); \
  return out;                     \
}                                 \
\
_sol_ \
V V##_sub(V a, V b) {            \
  const V out = UX2_OP(a, -, b); \
  return out;                    \
}                                \
\
_sol_ \
V V##_subf(V v, T f) {            \
  const V out = UX2_OPF(v, -, f); \
  return out;                     \
}                                 \
\
_sol_ \
V V##_fsub(T f, V v) {            \
  const V out = UX2_FOP(f, -, v); \
  return out;                     \
}                                 \
\
_sol_ \
V V##_mul(V a, V b) {            \
  const V out = UX2_OP(a, *, b); \
  return out;                    \
}                                \
\
_sol_ \
V V##_mulf(V v, T f) {            \
  const V out = UX2_OPF(v, *, f); \
  return out;                     \
}                                 \
\
_sol_ \
V V##_div(V a, V b) {            \
  const V out = UX2_OP(a, /, b); \
  return out;                    \
}                                \
\
_sol_ \
V V##_divf(V v, T f) {            \
  const V out = UX2_OPF(v, /, f); \
  return out;                     \
}                                 \
\
_sol_ \
V V##_fdiv(T f, V v) {           \
  const V out= UX2_FOP(f, /, v); \
  return out;                    \
}                                \
\
_sol_ \
V V##_fma(V a, V b, V c) {              \
  const V out = UX2_OP2(a, *, b, +, c); \
  return out;                           \
}                                       \
\
_sol_ \
V V##_fms(V a, V b, V c) {              \
  const V out = UX2_OP2(a, *, b, -, c); \
  return out;                           \
}                                       \

UX2(u8,   u8x2)
UX2(u16, u16x2)
UX2(u32, u32x2)
UX2(u64, u64x2)

#undef UX2
#undef UX2_OP
#undef UX2_OPF
#undef UX2_FOP
#undef UX2_OP2

#endif /* SOL_UX2_H */
