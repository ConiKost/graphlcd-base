/*
 * GraphLCD skin library
 *
 * skin.h  -  skin class
 *
 * This file is released under the GNU General Public License. Refer
 * to the COPYING file distributed with this package.
 *
 * based on text2skin
 *
 */

#ifndef _GLCDSKIN_SKIN_H_
#define _GLCDSKIN_SKIN_H_

#include <string>

#include "display.h"
#include "font.h"
#include "type.h"
#include "string.h"
#include "cache.h"
#include "config.h"
#include "variable.h"


namespace GLCD
{

class cSkin
{
    friend bool StartElem(const std::string & name, std::map<std::string,std::string> & attrs);
    friend bool EndElem(const std::string & name);

private:
    cSkinConfig & config;
    std::string name;
    std::string title;
    std::string version;
    tSize baseSize;

    cSkinFonts fonts;
    cSkinDisplays displays;
    cSkinVariables mVariables;
    cImageCache * mImageCache;

public:
    cSkin(cSkinConfig & Config, const std::string & Name);
    ~cSkin(void);

    void SetBaseSize(int width, int height);

    cSkinFont * GetFont(const std::string & Id);
    cSkinDisplay * GetDisplay(const std::string & Id);
    cSkinVariable * GetVariable(const std::string & Id);

    cSkinConfig & Config(void) { return config; }
    const std::string & Name(void) const { return name; }
    const std::string & Title(void) const { return title; }
    const std::string & Version(void) const { return version; }
    const tSize & BaseSize(void) const { return baseSize; }

    cImageCache * ImageCache(void) { return mImageCache; }
};

} // end of namespace

#endif
