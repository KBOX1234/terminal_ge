struct vector_2 p2v(struct point pt){
    struct vector_2 v;

    v.x = (int)round(pt.x);
    v.y = (int)round(pt.y);

    return v;
}

struct point v2p(struct vector_2 v){
    struct point pt;

    pt.x = (float)v.x;
    pt.y = (float)v.y;

    return pt;
}