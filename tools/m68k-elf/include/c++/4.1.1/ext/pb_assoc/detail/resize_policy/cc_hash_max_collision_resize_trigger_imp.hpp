// -*- C++ -*-

// Copyright (C) 2005 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.

// Permission to use, copy, modify, sell, and distribute this software
// is hereby granted without fee, provided that the above copyright
// notice appears in all copies, and that both that copyright notice and
// this permission notice appear in supporting documentation. None of
// the above authors, nor IBM Haifa Research Laboratories, make any
// representation about the suitability of this software for any
// purpose. It is provided "as is" without express or implied warranty.

/*
 * @file cc_hash_max_collision_check_resize_trigger_imp.hpp
 * Contains an implementation of cc_hash_max_collision_check_resize_trigger.
 */

PB_ASSOC_CLASS_T_DEC
pb_assoc::detail::int_to_type<External_Load_Access>
PB_ASSOC_CLASS_C_DEC::s_external_load_access_ind;

PB_ASSOC_CLASS_T_DEC
PB_ASSOC_CLASS_C_DEC::
cc_hash_max_collision_check_resize_trigger(float load) :
  m_load(load),
  m_size(0),
  m_num_col(0),
  m_max_col(0),
  m_resize_needed(false)
{ }

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_find_search_start()
{ }

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_find_search_collision()
{ }

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_find_search_end()
{ }

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_insert_search_start()
{
  m_num_col = 0;
}

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_insert_search_collision()
{
  ++m_num_col;
}

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_insert_search_end()
{
  PB_ASSOC_DBG_ASSERT(NOTHING_HT_RESIZE_ACTION == 0);

  m_resize_needed =
    m_resize_needed || (m_num_col >= m_max_col);
}

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_erase_search_start()
{ }

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_erase_search_collision()
{ }

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_erase_search_end()
{ }

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_inserted(size_type num_e)
{
  PB_ASSOC_DBG_ASSERT(num_e <= m_size);

  if (num_e == m_size)
    m_resize_needed = true;
}

PB_ASSOC_CLASS_T_DEC
inline void
PB_ASSOC_CLASS_C_DEC::
notify_erased(size_type num_e)
{
  PB_ASSOC_DBG_ASSERT(num_e <= m_size);

  m_resize_needed = false;
}

PB_ASSOC_CLASS_T_DEC
void
PB_ASSOC_CLASS_C_DEC::
notify_cleared()
{
  m_resize_needed = false;
}

PB_ASSOC_CLASS_T_DEC
inline bool
PB_ASSOC_CLASS_C_DEC::
is_resize_needed() const
{
  return (m_resize_needed);
}

PB_ASSOC_CLASS_T_DEC
inline bool
PB_ASSOC_CLASS_C_DEC::
is_grow_needed(size_type /*size*/, size_type /*num_used_e*/) const
{
  PB_ASSOC_DBG_ASSERT(m_resize_needed);

  return (true);
}

PB_ASSOC_CLASS_T_DEC
inline bool
PB_ASSOC_CLASS_C_DEC::
is_shrink_needed(size_type size, size_type num_used_e) const
{
  PB_ASSOC_DBG_ASSERT(m_resize_needed);

  return (false);
}

PB_ASSOC_CLASS_T_DEC
void
PB_ASSOC_CLASS_C_DEC::
notify_resized(size_type new_size)
{
  m_size = new_size;

  // max_col <-- \sqrt{2 load \ln( 2 m \ln( m ) ) }

  const double ln_arg = 2*  m_size*  ::log( (double)m_size);

  m_max_col = (size_type)::ceil(  ::sqrt(2*   m_load*  ::log(ln_arg) ) );

  m_num_col = 0;

  m_resize_needed = false;
}

PB_ASSOC_CLASS_T_DEC
void
PB_ASSOC_CLASS_C_DEC::
notify_externally_resized(size_type new_size)
{
  notify_resized(new_size);
}

PB_ASSOC_CLASS_T_DEC
void
PB_ASSOC_CLASS_C_DEC::
swap(PB_ASSOC_CLASS_C_DEC& r_other)
{
  std::swap(m_load, r_other.m_load);

  std::swap(m_size, r_other.m_size);

  std::swap(m_num_col, r_other.m_num_col);

  std::swap(m_max_col, r_other.m_max_col);

  std::swap(m_resize_needed, r_other.m_resize_needed);
}

PB_ASSOC_CLASS_T_DEC
inline float
PB_ASSOC_CLASS_C_DEC::
get_load_imp(pb_assoc::detail::int_to_type<true>) const
{
  return (m_load);
}
