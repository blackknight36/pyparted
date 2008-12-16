/*
 * pydevice.h
 * pyparted type objects for pydevice.c
 *
 * Copyright (C) 2007, 2008  Red Hat, Inc.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions of
 * the GNU General Public License v.2, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY expressed or implied, including the implied warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.  You should have received a copy of the
 * GNU General Public License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.  Any Red Hat trademarks that are incorporated in the
 * source code or documentation are not subject to the GNU General Public
 * License and may only be used or replicated with the express permission of
 * Red Hat, Inc.
 *
 * Red Hat Author(s): David Cantrell <dcantrell@redhat.com>
 *                    Chris Lumens <clumens@redhat.com>
 */

#ifndef TYPEOBJECTS_PYDEVICE_H_INCLUDED
#define TYPEOBJECTS_PYDEVICE_H_INCLUDED

#include <Python.h>
#include <structmember.h>

/* _ped.CHSGeometry type object */
static PyMemberDef _ped_CHSGeometry_members[] = {
    {NULL}
};

static PyMethodDef _ped_CHSGeometry_methods[] = {
    {NULL}
};

static PyGetSetDef _ped_CHSGeometry_getset[] = {
    {"cylinders", (getter) _ped_CHSGeometry_get,
                  (setter) _ped_CHSGeometry_set,
                  "The number of cylinders.", "cylinders"},
    {"heads", (getter) _ped_CHSGeometry_get,
              (setter) _ped_CHSGeometry_set,
              "The number of heads", "heads"},
    {"sectors", (getter) _ped_CHSGeometry_get,
                (setter) _ped_CHSGeometry_set,
                "The number of sectors", "sectors"},
    {NULL}  /* Sentinel */
};

PyTypeObject _ped_CHSGeometry_Type_obj = {
    PyObject_HEAD_INIT(&PyType_Type)
    .tp_name = "_ped.CHSGeometry",
    .tp_basicsize = sizeof(_ped_CHSGeometry),
 /* .tp_itemsize = XXX */
    .tp_dealloc = (destructor) _ped_CHSGeometry_dealloc,
 /* .tp_print = XXX */
 /* .tp_getattr = XXX */
 /* .tp_setattr = XXX */
 /* .tp_compare = XXX */
 /* .tp_repr = XXX */
 /* .tp_as_number = XXX */
 /* .tp_as_sequence = XXX */
 /* .tp_as_mapping = XXX */
 /* .tp_hash = XXX */
    .tp_call = NULL,
 /* .tp_str = XXX */
    .tp_getattro = PyObject_GenericGetAttr,
    .tp_setattro = PyObject_GenericSetAttr,
 /* .tp_as_buffer = XXX */
    .tp_flags = Py_TPFLAGS_HAVE_CLASS | Py_TPFLAGS_BASETYPE |
                Py_TPFLAGS_HAVE_GC,
    .tp_doc = _ped_CHSGeometry_doc,
    .tp_traverse = (traverseproc) _ped_CHSGeometry_traverse,
    .tp_clear = (inquiry) _ped_CHSGeometry_clear,
 /* .tp_richcompare = XXX */
 /* .tp_weaklistoffset = XXX */
 /* .tp_iter = XXX */
 /* .tp_iternext = XXX */
    .tp_methods = _ped_CHSGeometry_methods,
    .tp_members = _ped_CHSGeometry_members,
    .tp_getset = _ped_CHSGeometry_getset,
    .tp_base = NULL,
 /* .tp_dict = XXX */
 /* .tp_descr_get = XXX */
 /* .tp_descr_set = XXX */
 /* .tp_dictoffset = XXX */
    .tp_init = NULL,
    .tp_alloc = PyType_GenericAlloc,
    .tp_new = NULL,
 /* .tp_free = XXX */
 /* .tp_is_gc = XXX */
    .tp_bases = NULL,
 /* .tp_del = XXX */
};

/* _ped.Device type object */
static PyMemberDef _ped_Device_members[] = {
    {"hw_geom", T_OBJECT, offsetof(_ped_Device, hw_geom), 0,
                "The CHSGeometry of the Device as reported by the hardware."},
    {"bios_geom", T_OBJECT, offsetof(_ped_Device, bios_geom), 0,
                  "The CHSGeometry of the Device as reported by the BIOS."},
    {NULL}
};

static PyMethodDef _ped_Device_methods[] = {
    /*
     * This is a unique function as it's in pydisk.c, but is really
     * a method on _ped.Device, so it's part of this PyMethod Def
     */
    {"disk_probe", (PyCFunction) py_ped_disk_probe, METH_VARARGS,
                   disk_probe_doc},

    /* These functions are all in pydevice.c */
    {"get_next", (PyCFunction) py_ped_device_get_next, METH_VARARGS,
                 device_get_next_doc},
    {"is_busy", (PyCFunction) py_ped_device_is_busy, METH_VARARGS,
                device_is_busy_doc},
    {"open", (PyCFunction) py_ped_device_open, METH_VARARGS,
             device_open_doc},
    {"close", (PyCFunction) py_ped_device_close, METH_VARARGS,
              device_close_doc},
    {"destroy", (PyCFunction) py_ped_device_destroy, METH_VARARGS,
                device_destroy_doc},
    {"cache_remove", (PyCFunction) py_ped_device_cache_remove,
                     METH_VARARGS, device_cache_remove_doc},
    {"begin_external_access", (PyCFunction) py_ped_device_begin_external_access,
                              METH_VARARGS, device_begin_external_access_doc},
    {"end_external_access", (PyCFunction) py_ped_device_end_external_access,
                            METH_VARARGS, device_end_external_access_doc},
    {"read", (PyCFunction) py_ped_device_read, METH_VARARGS,
             device_read_doc},
    {"write", (PyCFunction) py_ped_device_write, METH_VARARGS,
              device_write_doc},
    {"sync", (PyCFunction) py_ped_device_sync, METH_VARARGS,
             device_sync_doc},
    {"sync_fast", (PyCFunction) py_ped_device_sync_fast, METH_VARARGS,
                  device_sync_fast_doc},
    {"check", (PyCFunction) py_ped_device_check, METH_VARARGS,
              device_check_doc},
    {"get_constraint", (PyCFunction) py_ped_device_get_constraint,
                       METH_VARARGS, device_get_constraint_doc},
    {NULL}
};

static PyGetSetDef _ped_Device_getset[] = {
    {"model", (getter) _ped_Device_get, (setter) _ped_Device_set,
              "A brief description of the hardware, usually mfr and model.",
              "model"},
    {"path", (getter) _ped_Device_get, (setter) _ped_Device_set,
             "The operating system level path to the device node.", "path"},
    {"type", (getter) _ped_Device_get, (setter) _ped_Device_set,
             "The type of device, deprecated in favor of PedDeviceType", "type"},
    {"sector_size", (getter) _ped_Device_get, (setter) _ped_Device_set,
                    "Logical sector size.", "sector_size"},
    {"phys_sector_size", (getter) _ped_Device_get, (setter) _ped_Device_set,
                         "Physical sector size.", "phys_sector_size"},
    {"length", (getter) _ped_Device_get, (setter) _ped_Device_set,
               "Device length, in sectors (LBA).", "length"},
    {"open_count", (getter) _ped_Device_get, (setter) _ped_Device_set,
                   "How many times self.open() has been called.", "open_count"},
    {"read_only", (getter) _ped_Device_get, (setter) _ped_Device_set,
                  "Is the device opened in read-only mode?", "read_only"},
    {"external_mode", (getter) _ped_Device_get, (setter) _ped_Device_set,
                      "PedDevice external_mode", "external_mode"},
    {"dirty", (getter) _ped_Device_get, (setter) _ped_Device_set,
              "Have any unflushed changes been made to self?", "dirty"},
    {"boot_dirty", (getter) _ped_Device_get, (setter) _ped_Device_set,
                   "Have any unflushed changes been made to the bootloader?",
                   "boot_dirty"},
    {"host", (getter) _ped_Device_get, (setter) _ped_Device_set,
             "Any SCSI host ID associated with self.", "host"},
    {"did", (getter) _ped_Device_get, (setter) _ped_Device_set,
            "Any SCSI device ID associated with self.", "did"},
    {NULL}  /* Sentinel */
};

PyTypeObject _ped_Device_Type_obj = {
    PyObject_HEAD_INIT(&PyType_Type)
    .tp_name = "_ped.Device",
    .tp_basicsize = PyGC_HEAD_SIZE + sizeof(_ped_Device),
    .tp_itemsize = 0,
    .tp_dealloc = (destructor) _ped_Device_dealloc,
 /* .tp_print = XXX */
 /* .tp_getattr = XXX */
 /* .tp_setattr = XXX */
 /* .tp_compare = XXX */
 /* .tp_repr = XXX */
 /* .tp_as_number = XXX */
 /* .tp_as_sequence = XXX */
 /* .tp_as_mapping = XXX */
 /* .tp_hash = XXX */
    .tp_call = NULL,
 /* .tp_str = XXX */
    .tp_getattro = PyObject_GenericGetAttr,
    .tp_setattro = PyObject_GenericSetAttr,
 /* .tp_as_buffer = XXX */
    .tp_flags = Py_TPFLAGS_HAVE_CLASS | Py_TPFLAGS_BASETYPE |
                Py_TPFLAGS_HAVE_GC,
    .tp_doc = _ped_Device_doc,
    .tp_traverse = (traverseproc) _ped_Device_traverse,
    .tp_clear = (inquiry) _ped_Device_clear,
 /* .tp_richcompare = XXX */
 /* .tp_weaklistoffset = XXX */
 /* .tp_iter = XXX */
 /* .tp_iternext = XXX */
    .tp_methods = _ped_Device_methods,
    .tp_members = _ped_Device_members,
    .tp_getset = _ped_Device_getset,
    .tp_base = NULL,
    .tp_dict = NULL,
 /* .tp_descr_get = XXX */
 /* .tp_descr_set = XXX */
 /* .tp_dictoffset = XXX */
    .tp_init = NULL,
    .tp_alloc = PyType_GenericAlloc,
    .tp_new = NULL,
 /* .tp_free = XXX */
 /* .tp_is_gc = XXX */
    .tp_bases = NULL,
 /* .tp_del = XXX */
};

#endif /* TYPEOBJECTS_PYDEVICE_H_INCLUDED */

/* vim:tw=78:ts=4:et:sw=4
 */
