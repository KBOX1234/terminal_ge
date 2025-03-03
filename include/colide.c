
bool do_entities_colide(struct entity* e1, struct entity* e2){

    //automaticly returns false
    if(el->has_colide_box == false) return false;
    if(e2->has_colide_box == false) return false;

    return doesBoxAndBoxColide(e1->box, e2->box);
}

bool does_entity_and_object_colide(struct entity* e, struct object* o){
    //automaticly returns false
    if(e->has_colide_box == false || o->has_colide_box == false) return false;

    return doesBoxAndBoxColide(e->box, o->box);

}