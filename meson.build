project('wxTestPad', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3']
)

wx_dep = dependency(
  'wxwidgets', version : '>=3.0.0', modules : ['ribbon', 'core', 'base']
)

sources = files(
  'gui/buildergen/TpGUI.cpp',
  'gui/DialogBase.cpp',
  'gui/MainWindow.cpp',
  'gui/FindDialog.cpp',
  'gui/ReplaceDialog.cpp',
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
