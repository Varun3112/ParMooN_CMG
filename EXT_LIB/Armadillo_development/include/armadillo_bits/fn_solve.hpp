// Copyright 2008-2016 Conrad Sanderson (http://conradsanderson.id.au)
// Copyright 2008-2016 National ICT Australia (NICTA)
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------


//! \addtogroup fn_solve
//! @{



//
// solve_gen


template<typename T1, typename T2>
arma_warn_unused
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, const Glue<T1, T2, glue_solve_gen> >::result
solve
  (
  const Base<typename T1::elem_type,T1>& A,
  const Base<typename T1::elem_type,T2>& B,
  const solve_opts::opts&                opts = solve_opts::none
  )
  {
  arma_extra_debug_sigprint();
  
  return Glue<T1, T2, glue_solve_gen>(A.get_ref(), B.get_ref(), opts.flags);
  }



template<typename T1, typename T2>
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, bool >::result
solve
  (
         Mat<typename T1::elem_type>&    out,
  const Base<typename T1::elem_type,T1>& A,
  const Base<typename T1::elem_type,T2>& B,
  const solve_opts::opts&                opts = solve_opts::none
  )
  {
  arma_extra_debug_sigprint();
  
  return glue_solve_gen::apply(out, A.get_ref(), B.get_ref(), opts.flags);
  }



//
// solve_tri


template<typename T1, typename T2>
arma_warn_unused
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, const Glue<T1, T2, glue_solve_tri_default> >::result
solve
  (
  const Op<T1, op_trimat>&               A,
  const Base<typename T1::elem_type,T2>& B
  )
  {
  arma_extra_debug_sigprint();
  
  uword flags = uword(0);
  
  if(A.aux_uword_a == 0)  { flags |= solve_opts::flag_triu; }
  if(A.aux_uword_a == 1)  { flags |= solve_opts::flag_tril; }
  
  return Glue<T1, T2, glue_solve_tri_default>(A.m, B.get_ref(), flags);
  }



template<typename T1, typename T2>
arma_warn_unused
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, const Glue<T1, T2, glue_solve_tri> >::result
solve
  (
  const Op<T1, op_trimat>&               A,
  const Base<typename T1::elem_type,T2>& B,
  const solve_opts::opts&                opts
  )
  {
  arma_extra_debug_sigprint();
  
  uword flags = opts.flags;
  
  if(A.aux_uword_a == 0)  { flags |= solve_opts::flag_triu; }
  if(A.aux_uword_a == 1)  { flags |= solve_opts::flag_tril; }
  
  return Glue<T1, T2, glue_solve_tri>(A.m, B.get_ref(), flags);
  }



template<typename T1, typename T2>
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, bool >::result
solve
  (
         Mat<typename T1::elem_type>&    out,
  const   Op<T1, op_trimat>&             A,
  const Base<typename T1::elem_type,T2>& B
  )
  {
  arma_extra_debug_sigprint();
  
  uword flags = uword(0);
  
  if(A.aux_uword_a == 0)  { flags |= solve_opts::flag_triu; }
  if(A.aux_uword_a == 1)  { flags |= solve_opts::flag_tril; }
  
  return glue_solve_tri_default::apply(out, A.m, B.get_ref(), flags);
  }



template<typename T1, typename T2>
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, bool >::result
solve
  (
         Mat<typename T1::elem_type>&    out,
  const   Op<T1, op_trimat>&             A,
  const Base<typename T1::elem_type,T2>& B,
  const solve_opts::opts&                opts
  )
  {
  arma_extra_debug_sigprint();
  
  uword flags = opts.flags;
  
  if(A.aux_uword_a == 0)  { flags |= solve_opts::flag_triu; }
  if(A.aux_uword_a == 1)  { flags |= solve_opts::flag_tril; }
  
  return glue_solve_tri::apply(out, A.m, B.get_ref(), flags);
  }



//! @}
