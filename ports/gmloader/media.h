#ifndef __MEDIA_PLATFORM_H__
#define __MEDIA_PLATFORM_H__

extern void deinit_display();
extern int init_display(int w, int h);
extern void get_display_size(int *w, int *h);
extern void flip_display_surface();
extern int update_input();

#endif /* __MEDIA_PLATFORM_H__ */