# GCmalloc
Pseudo ramasse-miette (garbage collector)

### les fonctions:
  * __\*get\_new\_obj(int size, int id);__
  * __\*resize\_obj(void *oldobj, int new\_size);__
  * __\*get\_new\_obj\_set(int size, int id);__
  * __obj\_mem\_set(void *obj);__
  * __free\_exept\_obj(void *obj);__
  * __free\_by\_id(int id);__
  * __free\_me\_all();__
  * __free\_me\_all_secure();__

### Description:
  * __get\_new\_obj()__ alloue _size_ octets, et renvoie un pointeur sur la mémoire allouée.
  * __resize\_obj()__ modifie la taille du bloc de mémoire pointé par _oldobj_ pour l'amener à une taille de _new\_size_ octets. Renvoie un pointeur sur la mémoire allouée.
  * __get\_new\_obj\_set()__ alloue _size_ octets, et renvoie un pointeur sur la mémoire allouée. Cette zone est remplie avec des zéros. 
  * __obj\_mem\_set()__ remplie la zone de memoire pointer par _obj_ avec des zéros.
  * __free\_exept\_obj()__ libère l'espace mémoire pointé par _obj_.
  * __free\_by\_id()__ libère l'espace mémoire de toute les pointeurs qui on pour id _id_.
  * __free\_me\_all()__ libère tout les allocations memoires faites par _get\_new\_obj()_, _get\_new\_obj\_set()_ ou _resize\_obj()_.
  * __free\_me\_all_secure()__ meme chose que _free\_me\_all_ mais remplie la zone de zeros avant de libèrer la memoire.
