project('wxTestPad', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3']
)

wx_dep = dependency(
  'wxwidgets', version : '>=3.0.0', modules : ['ribbon', 'core', 'base']
)

sources = files(
  'gui/buildergen/TpGUI.cpp',
  'gui/TpMainFrame.cpp',
  'gui/TpFindDialog.cpp',
  'gui/TpReplaceDialog.cpp',
  'notepad/Notepad.cpp',
  'utilities/logging/TpLogFormatter.cpp',
  'utilities/Utils.cpp',
  'wxtestpad.cpp',
)

include_dir = include_directories('./')

executable('wxTestPad', sources,
  include_directories : include_dir,
  dependencies : [wx_dep],
  install : false
)
