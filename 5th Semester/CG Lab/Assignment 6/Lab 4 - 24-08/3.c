



void draw_line(int xstart, int xend, int ystart, int yend) {
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = xend - xstart;
    dy = yend - ystart;

    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    incx = 1;

    if (xend < xstart) incx = -1;
    incy = 1;

    if (yend < ystart) incy = -1;
    x = xstart;
    y = ystart;

    if (dx > dy) {
        draw_pixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;

        for (int i = 0; i < dx; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1;
            }
            else {
                draw_pixel(x, y);
                e = 2 * dx - dy;
                inc1 = 2 * (dx - dy);
                inc2 = 2 * dx;

                for(int)
            }
        }
    }
}