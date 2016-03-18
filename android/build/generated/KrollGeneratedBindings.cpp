/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /private/var/folders/25/yvdn9h053sv3htdkzq8558k40000gn/T/fuerst/tiosmdroid-generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/private/var/folders/25/yvdn9h053sv3htdkzq8558k40000gn/T/fuerst/tiosmdroid-generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "ti.osmdroid.ViewProxy.h"
#include "ti.osmdroid.TiosmdroidModule.h"
#include "ti.osmdroid.AnnotationProxy.h"


#line 15 "/private/var/folders/25/yvdn9h053sv3htdkzq8558k40000gn/T/fuerst/tiosmdroid-generated/KrollGeneratedBindings.gperf"
struct titanium::bindings::BindEntry;
/* maximum key range = 8, duplicates = 0 */

class TiosmdroidBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct titanium::bindings::BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
TiosmdroidBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct titanium::bindings::BindEntry *
TiosmdroidBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 3,
      MIN_WORD_LENGTH = 21,
      MAX_WORD_LENGTH = 28,
      MIN_HASH_VALUE = 21,
      MAX_HASH_VALUE = 28
    };

  static struct titanium::bindings::BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 17 "/private/var/folders/25/yvdn9h053sv3htdkzq8558k40000gn/T/fuerst/tiosmdroid-generated/KrollGeneratedBindings.gperf"
      {"ti.osmdroid.ViewProxy", ::ti::osmdroid::tiosmdroid::ViewProxy::bindProxy, ::ti::osmdroid::tiosmdroid::ViewProxy::dispose},
      {""}, {""}, {""}, {""}, {""},
#line 19 "/private/var/folders/25/yvdn9h053sv3htdkzq8558k40000gn/T/fuerst/tiosmdroid-generated/KrollGeneratedBindings.gperf"
      {"ti.osmdroid.AnnotationProxy", ::ti::osmdroid::tiosmdroid::AnnotationProxy::bindProxy, ::ti::osmdroid::tiosmdroid::AnnotationProxy::dispose},
#line 18 "/private/var/folders/25/yvdn9h053sv3htdkzq8558k40000gn/T/fuerst/tiosmdroid-generated/KrollGeneratedBindings.gperf"
      {"ti.osmdroid.TiosmdroidModule", ::ti::osmdroid::TiosmdroidModule::bindProxy, ::ti::osmdroid::TiosmdroidModule::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 20 "/private/var/folders/25/yvdn9h053sv3htdkzq8558k40000gn/T/fuerst/tiosmdroid-generated/KrollGeneratedBindings.gperf"

