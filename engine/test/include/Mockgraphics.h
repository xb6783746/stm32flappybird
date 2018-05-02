/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKGRAPHICS_H
#define _MOCKGRAPHICS_H

#include "graphics.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void Mockgraphics_Init(void);
void Mockgraphics_Destroy(void);
void Mockgraphics_Verify(void);




#define graphics_clear_Expect(color) graphics_clear_CMockExpect(__LINE__, color)
void graphics_clear_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_color_t color);
#define graphics_draw_rect_Expect(obj) graphics_draw_rect_CMockExpect(__LINE__, obj)
void graphics_draw_rect_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_rectangle_t* obj);
#define graphics_draw_frect_Expect(obj) graphics_draw_frect_CMockExpect(__LINE__, obj)
void graphics_draw_frect_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_filled_rectangle_t* obj);
#define graphics_draw_circle_Expect(obj) graphics_draw_circle_CMockExpect(__LINE__, obj)
void graphics_draw_circle_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_circle_t* obj);
#define graphics_draw_fcircle_Expect(obj) graphics_draw_fcircle_CMockExpect(__LINE__, obj)
void graphics_draw_fcircle_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_filled_circle_t* obj);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif