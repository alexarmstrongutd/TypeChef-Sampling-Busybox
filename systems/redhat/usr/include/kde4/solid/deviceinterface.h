/*  This file is part of the KDE project
    Copyright (C) 2006-2007 Kevin Ottens <ervin@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License version 2 as published by the Free Software Foundation.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.

*/

#ifndef SOLID_DEVICEINTERFACE_H
#define SOLID_DEVICEINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QBool>

#include <solid/solid_export.h>

namespace Solid
{
    class Device;
    class DevicePrivate;
    class Predicate;
    class DeviceInterfacePrivate;

    /**
     * Base class of all the device interfaces.
     *
     * A device interface describes what a device can do. A device generally has
     * a set of device interfaces.
     */
    class SOLID_EXPORT DeviceInterface : public QObject
    {
        Q_OBJECT
        Q_ENUMS(Type)
        Q_DECLARE_PRIVATE(DeviceInterface)

    public:
        /**
         * This enum type defines the type of device interface that a Device can have.
         *
         * - Unknown : An undetermined device interface
         * - Processor : A processor
         * - Block : A block device
         * - StorageDrive : A storage drive
         * - Cdrom : A CD-ROM drive
         * - StorageVolume : A volume
         * - OpticalDisc : An optical disc
         * - Camera : A digital camera
         * - PortableMediaPlayer: A portable media player
         * - NetworkInterface: A network interface
         * - SerialInterface: A serial interface
         * - SmartCardReader: A smart card reader interface
         */
        enum Type { Unknown = 0, GenericInterface = 1, Processor = 2,
                    Block = 3, StorageAccess = 4, StorageDrive = 5,
                    OpticalDrive = 6, StorageVolume = 7, OpticalDisc = 8,
                    Camera = 9, PortableMediaPlayer = 10,
                    NetworkInterface = 11, AcAdapter = 12, Battery = 13,
                    Button = 14, AudioInterface = 15, DvbInterface = 16, Video = 17,
                    SerialInterface = 18, SmartCardReader = 19,
                    Last = 0xffff  };

        /**
         * Destroys a DeviceInterface object.
         */
        virtual ~DeviceInterface();

        /**
         * Indicates if this device interface is valid.
         * A device interface is considered valid if the device it is referring is available in the system.
         *
         * @return true if this device interface's device is available, false otherwise
         */
        bool isValid() const;

        /**
         *
         * @return the class name of the device interface type
         */
        static QString typeToString(Type type);

        /**
         *
         * @return the device interface type for the given class name
         */
        static Type stringToType(const QString &type);

        /**
         *
         * @return a description suitable to display in the UI of the device interface type
         * @since 4.4
         */
        static QString typeDescription(Type type);

    protected:
        /**
         * @internal
         * Creates a new DeviceInterface object.
         *
         * @param dd the private d member. It will take care of deleting it upon destruction.
         * @param backendObject the device interface object provided by the backend
         */
        DeviceInterface(DeviceInterfacePrivate &dd, QObject *backendObject);

        DeviceInterfacePrivate *d_ptr;

    private:
        friend class Device;
        friend class DevicePrivate;
    };
}

#endif
