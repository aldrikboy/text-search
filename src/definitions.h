#pragma once

#define TS_VERSION "v2.3.0"

// Find these with dumpbin [objfile] /SYMBOLS
extern "C"
{
extern unsigned char* _binary_LICENSE_start;
extern unsigned char* _binary_LICENSE_end;

extern unsigned char* _binary_imgui_LICENSE_start;
extern unsigned char* _binary_imgui_LICENSE_end;

extern unsigned char* _binary_glfw_LICENSE_start;
extern unsigned char* _binary_glfw_LICENSE_end;

extern unsigned char* _binary_imfiledialog_LICENSE_start;
extern unsigned char* _binary_imfiledialog_LICENSE_end;

extern unsigned char* _binary_misc_logo_64_png_start;
extern unsigned char* _binary_misc_logo_64_png_end;

extern unsigned char* _binary_misc_search_png_start;
extern unsigned char* _binary_misc_search_png_end;

extern unsigned char* _binary_misc_folder_png_start;
extern unsigned char* _binary_misc_folder_png_end;

extern unsigned char* _binary_misc_drop_png_start;
extern unsigned char* _binary_misc_drop_png_end;
}
