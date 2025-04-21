local lspconfig = require("lspconfig")
local util = lspconfig.util

lspconfig.clangd.setup({
  -- root markers so clangd knows where your project starts
  root_dir = util.root_pattern("compile_commands.json", "compile_flags.txt", ".git"),
  -- command-line flags: help clangd find your headers
  cmd = {
    "clangd",
    "--clang-tidy",
    "--header-insertion=never",
  },
  -- If you created compile_flags.txt in your project root, clangd will pick it up.
  -- Otherwise you can manually add include paths here:
  -- init_options = {
  --   extraArgs = {
  --     "-I" .. vim.fn.getcwd(),
  --     "-I" .. vim.fn.getcwd() .. "/include",
  --     "-I" .. vim.fn.getcwd() .. "/libft",
  --   },
  -- },

  on_attach = function(client, bufnr)
    -- enable omnifunc for <C-x><C-o>
    vim.api.nvim_buf_set_option(bufnr, "omnifunc", "v:lua.vim.lsp.omnifunc")

    local bufopts = { buffer = bufnr, silent = true }
    vim.keymap.set("n", "gd", vim.lsp.buf.definition, bufopts)
    vim.keymap.set("n", "K",  vim.lsp.buf.hover,      bufopts)
    vim.keymap.set("n", "<leader>rn", vim.lsp.buf.rename,     bufopts)
    vim.keymap.set("n", "<leader>ca", vim.lsp.buf.code_action,bufopts)
    vim.keymap.set("n", "gr", vim.lsp.buf.references, bufopts)
  end,

  -- optional: show diagnostics inline, in gutter, etc.
  handlers = {
    ["textDocument/publishDiagnostics"] = vim.lsp.with(
      vim.lsp.diagnostic.on_publish_diagnostics, {
        virtual_text = true,
        signs = true,
        underline = true,
        update_in_insert = false,
      }
    ),
  },
})

