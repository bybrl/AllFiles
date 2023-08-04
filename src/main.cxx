#include "FileFunctions/filefunctions.hpp"
#include <cargs.h>
#include <stdbool.h>
#include <stdlib.h>

/**
* This is the main configuration of all options available.
*/
static struct cag_option options[] = {
 {'d',
  "d",
  "show-dotfiles",
  NULL,
  "Shows dotfiles"},

 {'g',
   NULL,
   "guide",
   NULL,
  "Guide to AllFiles"},

 {'o',
  NULL,
  "other-dir",
   "VALUE",
  "Starts the program in another directory."},

 {'h',
  "h",
  "help",
  "Shows the command help"}};

/**
* This is a custom project configuration structure where you can store the
* parsed information.
*/
struct demo_configuration
{
 bool show_dotfiles;
 bool guide;
 const char *other_dir;
};

int main(int argc, char *argv[])
{
 char identifier;
 const char *value;
 cag_option_context context;
 struct demo_configuration config = {false, false, NULL};
 int param_index;

 /**
  * Now we just prepare the context and iterate over all options. Simple!
  */
 cag_option_prepare(&context, options, CAG_ARRAY_SIZE(options), argc, argv);
 while (cag_option_fetch(&context)) {
   identifier = cag_option_get(&context);
   switch (identifier) {
   case 'd':
     config.show_dotfiles = true;
     break;
   case 'g':
     config.guide = true;
     break;
   case 'k':
     value = cag_option_get_value(&context);
     config.other_dir = value;
     break;
   case 'h':
     printf("Usage: AllFiles [OPTION]...\n");
     printf("CLI file explorer.\n\n");
     cag_option_print(options, CAG_ARRAY_SIZE(options), stdout);
     return EXIT_SUCCESS;
   }
 }
 
 for (param_index = context.index; param_index < argc; ++param_index) {
   printf("additional parameter: %s\n", argv[param_index]);
 }

 return EXIT_SUCCESS;
}
// FileFunctions::concatenatefiles();
