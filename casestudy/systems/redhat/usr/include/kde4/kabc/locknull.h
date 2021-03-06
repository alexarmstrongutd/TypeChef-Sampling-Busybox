/*
    This file is part of libkabc.

    Copyright (c) 2003 Cornelius Schumacher <schumacher@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/
#ifndef KABC_LOCKNULL_H
#define KABC_LOCKNULL_H

#include "lock.h"
#include <QtCore/QString>

namespace KABC {

/**
  This class provides a lock without actually locking. It can be constructed in
  two ways: One that let all locks succeed and one that let all locks fail.
*/
class KABC_EXPORT LockNull : public Lock
{
  public:
    /**
      Creates an instance of the null lock.

      @param allowAccess if @c true all calls to lock() will "succeed",
                         if @c false all calls to lock() will "fail"
    */
    LockNull( bool allowAccess );
    ~LockNull();

    bool lock();
    bool unlock();

    QString error() const;

  private:
    class Private;
    Private *const d;
};

}

#endif
