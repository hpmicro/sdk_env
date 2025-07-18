# SPDX-License-Identifier: Apache-2.0

# from https://gist.github.com/korzo89/71a6de0f388f7cf8b349101b0134060c
function(from_hex HEX DEC)
    string(SUBSTRING "${HEX}" 2 -1 HEX)
    string(TOUPPER "${HEX}" HEX)
    set(_res 0)
    string(LENGTH "${HEX}" _strlen)

    while(_strlen GREATER 0)
        math(EXPR _res "${_res} * 16")
        string(SUBSTRING "${HEX}" 0 1 NIBBLE)
        string(SUBSTRING "${HEX}" 1 -1 HEX)
        if(NIBBLE STREQUAL "A")
            math(EXPR _res "${_res} + 10")
        elseif(NIBBLE STREQUAL "B")
            math(EXPR _res "${_res} + 11")
        elseif(NIBBLE STREQUAL "C")
            math(EXPR _res "${_res} + 12")
        elseif(NIBBLE STREQUAL "D")
            math(EXPR _res "${_res} + 13")
        elseif(NIBBLE STREQUAL "E")
            math(EXPR _res "${_res} + 14")
        elseif(NIBBLE STREQUAL "F")
            math(EXPR _res "${_res} + 15")
        else()
            math(EXPR _res "${_res} + ${NIBBLE}")
        endif()

        string(LENGTH "${HEX}" _strlen)
    endwhile()

    set(${DEC} ${_res} PARENT_SCOPE)
endfunction()

function(to_hex DEC HEX)
    if(DEC EQUAL 0)
        set(${HEX} "0x0" PARENT_SCOPE)
        return()
    endif()

    while(DEC GREATER 0)
        math(EXPR _val "${DEC} % 16")
        math(EXPR DEC "${DEC} / 16")
        if(_val EQUAL 10)
            set(_val "A")
        elseif(_val EQUAL 11)
            set(_val "B")
        elseif(_val EQUAL 12)
            set(_val "C")
        elseif(_val EQUAL 13)
            set(_val "D")
        elseif(_val EQUAL 14)
            set(_val "E")
        elseif(_val EQUAL 15)
            set(_val "F")
        endif()
        set(_res "${_val}${_res}")
    endwhile()
    set(${HEX} "0x${_res}" PARENT_SCOPE)
endfunction()
