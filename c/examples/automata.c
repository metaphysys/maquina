#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

struct stat st = {0};
#define SUBMODULE "Submodule.Maestro"

int checkDir(char *hola) {
  //printf("Comprobando si existe %s", hola);
  if (stat(hola, &st) == -1) {
    printf("%s no existe\n", hola);
    return 0;
  } else {
    printf("%s existe\n", hola);
    return 1;
  }
}

int main (int argc, char *argv[]) {

  if (argc < 3) {
    printf("Lo siento, faltan argumentos.\n");
  } else {
    printf("Nombre de entidad (singular): %s\n", argv[1]);
    printf("Nombre de entidad (plural): %s\n", argv[2]);
      
    if (checkDir(&SUBMODULE)) {
      char core[100] = SUBMODULE;
      char app[100] = SUBMODULE;
      char coreshared[100] = SUBMODULE;
      char appshared[100] = SUBMODULE;
			
      strcat(core,       "/Proyecta.PPlus.Core");
      strcat(app,        "/Proyecta.PPlus.Application");
      strcat(coreshared, "/Proyecta.PPlus.Core.Shared");
      strcat(appshared,  "/Proyecta.PPlus.Application.Shared");
      
      checkDir(&core);
      checkDir(&coreshared);
      checkDir(&app);
      checkDir(&appshared);
      
      //mkdir("%s/directory", SUBMODULE, 0700);
    }

  }

  return(0);
}
