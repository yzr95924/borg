.. IMPORTANT: this file is auto-generated from borg's built-in help, do not edit!

.. _borg_extract:

borg extract
------------
.. code-block:: none

    borg [common options] extract [options] ARCHIVE [PATH...]

.. only:: html

    .. class:: borg-options-table

    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    | **positional arguments**                                                                                                                                                                                  |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``ARCHIVE``                           | archive to extract                                                                                        |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``PATH``                              | paths to extract; patterns are supported                                                                  |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    | **optional arguments**                                                                                                                                                                                    |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--list``                            | output verbose list of items (files, dirs, ...)                                                           |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``-n``, ``--dry-run``                 | do not actually change any files                                                                          |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--numeric-owner``                   | only obey numeric user and group identifiers                                                              |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--nobsdflags``                      | do not extract/set bsdflags (e.g. NODUMP, IMMUTABLE)                                                      |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--noacls``                          | do not extract/set ACLs                                                                                   |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--noxattrs``                        | do not extract/set xattrs                                                                                 |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--stdout``                          | write all extracted data to stdout                                                                        |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--sparse``                          | create holes in output sparse file from all-zero chunks                                                   |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    | .. class:: borg-common-opt-ref                                                                                                                                                                            |
    |                                                                                                                                                                                                           |
    | :ref:`common_options`                                                                                                                                                                                     |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    | **Exclusion options**                                                                                                                                                                                     |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``-e PATTERN``, ``--exclude PATTERN`` | exclude paths matching PATTERN                                                                            |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--exclude-from EXCLUDEFILE``        | read exclude patterns from EXCLUDEFILE, one per line                                                      |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--pattern PATTERN``                 | experimental: include/exclude paths matching PATTERN                                                      |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--patterns-from PATTERNFILE``       | experimental: read include/exclude patterns from PATTERNFILE, one per line                                |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+
    |                                                       | ``--strip-components NUMBER``         | Remove the specified number of leading path elements. Paths with fewer elements will be silently skipped. |
    +-------------------------------------------------------+---------------------------------------+-----------------------------------------------------------------------------------------------------------+

    .. raw:: html

        <script type='text/javascript'>
        $(document).ready(function () {
            $('.borg-options-table colgroup').remove();
        })
        </script>

.. only:: latex

    ARCHIVE
        archive to extract
    PATH
        paths to extract; patterns are supported


    optional arguments
        --list            output verbose list of items (files, dirs, ...)
        -n, --dry-run     do not actually change any files
        --numeric-owner    only obey numeric user and group identifiers
        --nobsdflags      do not extract/set bsdflags (e.g. NODUMP, IMMUTABLE)
        --noacls          do not extract/set ACLs
        --noxattrs        do not extract/set xattrs
        --stdout          write all extracted data to stdout
        --sparse          create holes in output sparse file from all-zero chunks


    :ref:`common_options`
        |

    Exclusion options
        -e PATTERN, --exclude PATTERN     exclude paths matching PATTERN
        --exclude-from EXCLUDEFILE        read exclude patterns from EXCLUDEFILE, one per line
        --pattern PATTERN                 experimental: include/exclude paths matching PATTERN
        --patterns-from PATTERNFILE       experimental: read include/exclude patterns from PATTERNFILE, one per line
        --strip-components NUMBER         Remove the specified number of leading path elements. Paths with fewer elements will be silently skipped.


Description
~~~~~~~~~~~

This command extracts the contents of an archive. By default the entire
archive is extracted but a subset of files and directories can be selected
by passing a list of ``PATHs`` as arguments. The file selection can further
be restricted by using the ``--exclude`` option.

See the output of the "borg help patterns" command for more help on exclude patterns.

By using ``--dry-run``, you can do all extraction steps except actually writing the
output data: reading metadata and data chunks from the repo, checking the hash/hmac,
decrypting, decompressing.

``--progress`` can be slower than no progress display, since it makes one additional
pass over the archive metadata.

.. note::

    Currently, extract always writes into the current working directory ("."),
    so make sure you ``cd`` to the right place before calling ``borg extract``.