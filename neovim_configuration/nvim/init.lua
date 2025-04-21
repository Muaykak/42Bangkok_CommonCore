-- ─── Plugin Manager ─────────────────────────────────────

vim.g.mapleader = " "
vim.g.maplocalleader = "\\"
require ("config.lazy")

-- ─── nvim-tree Setup ───────────────────────────────────
require("nvim-tree").setup()

-- ─── Keybinding for nvim-tree ──────────────────────────
vim.keymap.set('n', '<localleader>e', ':NvimTreeToggle<CR>', { noremap = true, silent = true })

-- Show diagnostics inline in the gutter
vim.o.signcolumn = "yes"  -- Always show sign column

-- Set up diagnostic display
vim.diagnostic.config({
  virtual_text = true,  -- Display errors/warnings inline on the line
  signs = true,         -- Show symbols in the sign column
  update_in_insert = true,  -- Update diagnostics while typing
  underline = true,     -- Underline issues
})

-- ─── Basic Options ─────────────────────────────────────
vim.opt.number = true           -- Show line numbers
vim.opt.relativenumber = true   -- Show relative line numbers
vim.opt.tabstop = 4             -- Set tabstop
vim.opt.shiftwidth = 4          -- Set shiftwidth
vim.opt.smartindent = true      -- Enable smart indent
vim.opt.autoindent = true       -- Enable auto indent
vim.cmd 'syntax enable'         -- Enable syntax highlighting

-- ─── Colorscheme ───────────────────────────────────────
vim.cmd 'colorscheme tokyonight'

-- ─── Custom 42 Variables ───────────────────────────────
vim.g.user42 = 'srussame'
vim.g.mail42 = 'sutawith@gmail.com'

