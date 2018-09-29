#include <stdlib.h>
#include <stdio.h>
#include <fontconfig/fontconfig.h>

int main(int argc, char** argv){
  if(argc < 2){
    fprintf(stderr, "No font match given\n");
    exit(EXIT_FAILURE);
  }

  FcConfig* config = FcInitLoadConfigAndFonts();
  FcPattern* pat = FcNameParse((const FcChar8*)argv[1]);
  FcConfigSubstitute(config, pat, FcMatchPattern);
  FcDefaultSubstitute(pat);

  FcResult result;
  FcPattern* font = FcFontMatch(config, pat, &result);
  if(font){
    FcChar8* file = NULL;
    if(FcPatternGetString(font, FC_FILE, 0, &file) == FcResultMatch){
      printf("%s\n", file);
    }
    FcPatternDestroy(font);
  }

  FcPatternDestroy(pat);
  return 0;
}
