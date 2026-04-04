# Quick Start Guide

Your mechanical keyboard project is ready to share with the world!

## Option 1: Automatic Upload (Recommended)

Simply run:
```powershell
.\upload-to-github.ps1
```

The script will:
- Ask for your GitHub username
- Set up the git remote
- Push your code to GitHub
- Show you the final URL

## Option 2: Manual Upload

Follow the detailed instructions in `GITHUB_UPLOAD.md`

## What You Get

✅ QMK firmware ready to compile
✅ Complete build documentation with diagrams
✅ Troubleshooting guide
✅ All source code versioned in git

## Next Steps After Upload

1. Visit your GitHub repository
2. Upload build photos to the `images/` folder
3. Share the link with friends and the community!

## File Structure

```
mechanical-keyboard-pico/
├── config.h                 # Hardware pin configuration
├── keymaps/
│   └── default/keymap.c    # Key layout definitions
├── rules.mk                 # Build configuration
├── info.json                # Keyboard metadata
├── README.md                # Build story and documentation
├── images/                  # Folder for build photos
├── docs/
│   └── pinout.md            # GPIO pin reference
├── GITHUB_UPLOAD.md         # Upload instructions
├── upload-to-github.ps1     # Automated upload script
└── .gitignore               # Git configuration
```

## Questions?

See `GITHUB_UPLOAD.md` for detailed step-by-step instructions.
