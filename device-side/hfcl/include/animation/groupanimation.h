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
** along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __NGUX_ANIMATIONGROUP_H__
#define __NGUX_ANIMATIONGROUP_H__

#include "nguxanimation.h"

NAMESPACE_BEGIN

class GroupAnimation : public Animation
{
	public:
		LIST (Animation *, AMILIST);
		
		GroupAnimation(enum EffAnimationType type, GroupAnimation * parent = NULL);

		~GroupAnimation(); 
		void setProperty(int id, void *curvalue) {/* do nothing */}

		void add(Animation *ani);
    protected:
        virtual void onStart();

	private:
		AMILIST m_amiList;
};

NAMESPACE_END

#endif //__NGUX_ANIMATIONGROUP_H__