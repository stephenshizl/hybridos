/*
** HFCL - HybridOS Foundation Class Library
**
** Copyright (C) 2018 Beijing FMSoft Technologies Co., Ltd.
**
** This file is part of HFCL.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef HFCL_CSS_CSSDECLAREDGROUP_H_
#define HFCL_CSS_CSSDECLAREDGROUP_H_

#include <vector>

#include "../css/cssdeclared.h"
#include "../common/object.h"

namespace hfcl {

class View;
class Rootview;

VECTOR(CssDeclared*, CssDeclaredVec);

class CssDeclaredGroup : public RefCount {
public:
    CssDeclaredGroup() {}
    virtual ~CssDeclaredGroup();

    bool append(CssDeclared* css);

    friend class RootView;

protected:
    CssDeclaredVec m_css_vec;
};

typedef struct _CssWithSpecificity {
    CssDeclared*    css;
    DWORD           specif;
} CssWithSpecificity;

class CssDeclaredGroupWithSpecificity {
public:
    CssDeclaredGroupWithSpecificity() {}
    ~CssDeclaredGroupWithSpecificity();

    bool append(CssDeclared* css, DWORD specif);
    void sort();

    const std::vector<CssWithSpecificity>& getVec() const {
        return m_css_specif_vec;
    }

    friend class RootView;

protected:
    std::vector<CssWithSpecificity> m_css_specif_vec;
};

} // namespace hfcl

#endif /* HFCL_CSS_CSSDECLAREDGROUP_H_ */

