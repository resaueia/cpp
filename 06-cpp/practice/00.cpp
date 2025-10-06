/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:33:38 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/06 11:25:09 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

| Tipo de cast       | Uso principal                                                                | Equivalente (aproximado) em C   |
| ------------------ | ---------------------------------------------------------------------------- | ------------------------------- |
| `static_cast`      | conversões entre tipos compatíveis em tempo de compilação                    | `(type)value`                   |
| `reinterpret_cast` | conversões perigosas entre tipos *não relacionados* (ex: ponteiro → inteiro) | `(type)value`                   |
| `const_cast`       | adiciona ou remove o modificador `const`                                     | `(type)value`                   |
| `dynamic_cast`     | conversões seguras entre tipos relacionados por herança                      | *(não existe equivalente em C)* |

*/

//Challenge will be to figure out a way to identify the type of data stored
//in a given void pointer and then safely cast it back to its original type.

//weĺl only be using the static_cast as we are dealing only with scalar type.

/*

| Entrada  | Tipo detectado | Motivo                      |
| -------- | -------------- | --------------------------- |
| `"a"`    | `char`         | está entre aspas simples    |
| `"42"`   | `int`          | número inteiro sem ponto    |
| `"4.2"`  | `double`       | tem ponto e sem `f`         |
| `"4.2f"` | `float`        | tem ponto e termina com `f` |
| `"nan"`  | `double`       | pseudoliteral               |
| `"nanf"` | `float`        | pseudoliteral para float    |


*/