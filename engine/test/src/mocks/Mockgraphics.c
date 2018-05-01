/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "Mockgraphics.h"

static const char* CMockString_color = "color";
static const char* CMockString_graphics_clear = "graphics_clear";
static const char* CMockString_graphics_draw_circle = "graphics_draw_circle";
static const char* CMockString_graphics_draw_fcircle = "graphics_draw_fcircle";
static const char* CMockString_graphics_draw_frect = "graphics_draw_frect";
static const char* CMockString_graphics_draw_rect = "graphics_draw_rect";
static const char* CMockString_obj = "obj";

typedef struct _CMOCK_graphics_clear_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  gl_color_t Expected_color;

} CMOCK_graphics_clear_CALL_INSTANCE;

typedef struct _CMOCK_graphics_draw_rect_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  gl_rectangle_t* Expected_obj;

} CMOCK_graphics_draw_rect_CALL_INSTANCE;

typedef struct _CMOCK_graphics_draw_frect_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  gl_filled_rectangle_t* Expected_obj;

} CMOCK_graphics_draw_frect_CALL_INSTANCE;

typedef struct _CMOCK_graphics_draw_circle_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  gl_circle_t* Expected_obj;

} CMOCK_graphics_draw_circle_CALL_INSTANCE;

typedef struct _CMOCK_graphics_draw_fcircle_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  gl_filled_circle_t* Expected_obj;

} CMOCK_graphics_draw_fcircle_CALL_INSTANCE;

static struct MockgraphicsInstance
{
  CMOCK_MEM_INDEX_TYPE graphics_clear_CallInstance;
  CMOCK_MEM_INDEX_TYPE graphics_draw_rect_CallInstance;
  CMOCK_MEM_INDEX_TYPE graphics_draw_frect_CallInstance;
  CMOCK_MEM_INDEX_TYPE graphics_draw_circle_CallInstance;
  CMOCK_MEM_INDEX_TYPE graphics_draw_fcircle_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mockgraphics_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  UNITY_SET_DETAIL(CMockString_graphics_clear);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.graphics_clear_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_graphics_draw_rect);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.graphics_draw_rect_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_graphics_draw_frect);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.graphics_draw_frect_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_graphics_draw_circle);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.graphics_draw_circle_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_graphics_draw_fcircle);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.graphics_draw_fcircle_CallInstance, cmock_line, CMockStringCalledLess);
}

void Mockgraphics_Init(void)
{
  Mockgraphics_Destroy();
}

void Mockgraphics_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

void graphics_clear(gl_color_t color)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_graphics_clear_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_graphics_clear);
  cmock_call_instance = (CMOCK_graphics_clear_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.graphics_clear_CallInstance);
  Mock.graphics_clear_CallInstance = CMock_Guts_MemNext(Mock.graphics_clear_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_graphics_clear,CMockString_color);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_color), (void*)(&color), sizeof(gl_color_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_graphics_clear(CMOCK_graphics_clear_CALL_INSTANCE* cmock_call_instance, gl_color_t color)
{
  memcpy(&cmock_call_instance->Expected_color, &color, sizeof(gl_color_t));
}

void graphics_clear_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_color_t color)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_graphics_clear_CALL_INSTANCE));
  CMOCK_graphics_clear_CALL_INSTANCE* cmock_call_instance = (CMOCK_graphics_clear_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.graphics_clear_CallInstance = CMock_Guts_MemChain(Mock.graphics_clear_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_graphics_clear(cmock_call_instance, color);
  UNITY_CLR_DETAILS();
}

void graphics_draw_rect(gl_rectangle_t* obj)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_graphics_draw_rect_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_graphics_draw_rect);
  cmock_call_instance = (CMOCK_graphics_draw_rect_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.graphics_draw_rect_CallInstance);
  Mock.graphics_draw_rect_CallInstance = CMock_Guts_MemNext(Mock.graphics_draw_rect_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_graphics_draw_rect,CMockString_obj);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_obj), (void*)(obj), sizeof(gl_rectangle_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_graphics_draw_rect(CMOCK_graphics_draw_rect_CALL_INSTANCE* cmock_call_instance, gl_rectangle_t* obj)
{
  cmock_call_instance->Expected_obj = obj;
}

void graphics_draw_rect_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_rectangle_t* obj)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_graphics_draw_rect_CALL_INSTANCE));
  CMOCK_graphics_draw_rect_CALL_INSTANCE* cmock_call_instance = (CMOCK_graphics_draw_rect_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.graphics_draw_rect_CallInstance = CMock_Guts_MemChain(Mock.graphics_draw_rect_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_graphics_draw_rect(cmock_call_instance, obj);
  UNITY_CLR_DETAILS();
}

void graphics_draw_frect(gl_filled_rectangle_t* obj)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_graphics_draw_frect_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_graphics_draw_frect);
  cmock_call_instance = (CMOCK_graphics_draw_frect_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.graphics_draw_frect_CallInstance);
  Mock.graphics_draw_frect_CallInstance = CMock_Guts_MemNext(Mock.graphics_draw_frect_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_graphics_draw_frect,CMockString_obj);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_obj), (void*)(obj), sizeof(gl_filled_rectangle_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_graphics_draw_frect(CMOCK_graphics_draw_frect_CALL_INSTANCE* cmock_call_instance, gl_filled_rectangle_t* obj)
{
  cmock_call_instance->Expected_obj = obj;
}

void graphics_draw_frect_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_filled_rectangle_t* obj)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_graphics_draw_frect_CALL_INSTANCE));
  CMOCK_graphics_draw_frect_CALL_INSTANCE* cmock_call_instance = (CMOCK_graphics_draw_frect_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.graphics_draw_frect_CallInstance = CMock_Guts_MemChain(Mock.graphics_draw_frect_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_graphics_draw_frect(cmock_call_instance, obj);
  UNITY_CLR_DETAILS();
}

void graphics_draw_circle(gl_circle_t* obj)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_graphics_draw_circle_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_graphics_draw_circle);
  cmock_call_instance = (CMOCK_graphics_draw_circle_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.graphics_draw_circle_CallInstance);
  Mock.graphics_draw_circle_CallInstance = CMock_Guts_MemNext(Mock.graphics_draw_circle_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_graphics_draw_circle,CMockString_obj);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_obj), (void*)(obj), sizeof(gl_circle_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_graphics_draw_circle(CMOCK_graphics_draw_circle_CALL_INSTANCE* cmock_call_instance, gl_circle_t* obj)
{
  cmock_call_instance->Expected_obj = obj;
}

void graphics_draw_circle_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_circle_t* obj)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_graphics_draw_circle_CALL_INSTANCE));
  CMOCK_graphics_draw_circle_CALL_INSTANCE* cmock_call_instance = (CMOCK_graphics_draw_circle_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.graphics_draw_circle_CallInstance = CMock_Guts_MemChain(Mock.graphics_draw_circle_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_graphics_draw_circle(cmock_call_instance, obj);
  UNITY_CLR_DETAILS();
}

void graphics_draw_fcircle(gl_filled_circle_t* obj)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_graphics_draw_fcircle_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_graphics_draw_fcircle);
  cmock_call_instance = (CMOCK_graphics_draw_fcircle_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.graphics_draw_fcircle_CallInstance);
  Mock.graphics_draw_fcircle_CallInstance = CMock_Guts_MemNext(Mock.graphics_draw_fcircle_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_graphics_draw_fcircle,CMockString_obj);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_obj), (void*)(obj), sizeof(gl_filled_circle_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_graphics_draw_fcircle(CMOCK_graphics_draw_fcircle_CALL_INSTANCE* cmock_call_instance, gl_filled_circle_t* obj)
{
  cmock_call_instance->Expected_obj = obj;
}

void graphics_draw_fcircle_CMockExpect(UNITY_LINE_TYPE cmock_line, gl_filled_circle_t* obj)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_graphics_draw_fcircle_CALL_INSTANCE));
  CMOCK_graphics_draw_fcircle_CALL_INSTANCE* cmock_call_instance = (CMOCK_graphics_draw_fcircle_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.graphics_draw_fcircle_CallInstance = CMock_Guts_MemChain(Mock.graphics_draw_fcircle_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_graphics_draw_fcircle(cmock_call_instance, obj);
  UNITY_CLR_DETAILS();
}

