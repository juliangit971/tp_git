#ifndef PPM_H
#define PPM_H


// Objet pixel  
struct ppm_pixel {      
  unsigned char r;
  unsigned char g;
  unsigned char b;
};


// Initialiser la couleur d'un pixel avec les couleurs données en paramètres
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}


// Objet image stockant la taille de l'image et un tableau de pixel
struct ppm_image {
  unsigned int width;
  unsigned int height;
  struct ppm_pixel *px;
};


// Initialisation de l'image
int ppm_image_init(struct ppm_image *im, int w, int h);

// Destruction de l'image
int ppm_image_release(struct ppm_image *im);


// Permet de créer une image pixel par pixel
static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}


// Stocker l'image dans un fichier
int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */