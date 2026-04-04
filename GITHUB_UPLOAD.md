# How to Upload to GitHub

## Quick Option: Use the Automated Script

1. Open PowerShell in the project folder
2. Run:
```powershell
.\upload-to-github.ps1
```
3. Follow the prompts and enter your GitHub username

This script will automatically handle everything for you!

---

## Manual Option: Do It Step By Step

## Step 1: Create a GitHub Repository

1. Go to https://github.com/new
2. Sign in to your GitHub account (create one if you don't have it)
3. Fill in these details:
   - **Repository name:** `mechanical-keyboard-pico` (or whatever you want to call it)
   - **Description:** `60% Mechanical Keyboard with Raspberry Pi Pico and QMK Firmware`
   - **Public** or **Private** (your choice)
   - Check "Skip the initialization" - we already have a git repository
4. Click **Create repository**

## Step 2: Add GitHub as Remote and Push

Copy and paste these commands into PowerShell (replace `YOUR_USERNAME` with your GitHub username):

```powershell
cd c:\Users\kavin\mechanical_keyboard

git remote add origin https://github.com/YOUR_USERNAME/mechanical-keyboard-pico.git
git branch -M main
git push -u origin main
```

**Note:** You'll be prompted for GitHub credentials. Use:
- Username: Your GitHub username
- Password: A Personal Access Token (see "Creating a Token" below)

## Step 3: Add Images to Your Repository

After pushing, add your build photos:

1. Go to your GitHub repository online
2. Click "Add file" → "Upload files"
3. Drag and drop your images into the `images/` folder
4. Create filenames matching what README.md expects:
   - `pcb-layout.png` - PCB schematic
   - `pcb-routing.png` - PCB traces
   - `diode-diagram.png` - Diode connection diagram
   - `case-design.png` - Case CAD or photo
   - `case-assembled.png` - Case with PCB
   - `assembly-process.png` - Build photos
   - `finished-keyboard.png` - Final keyboard photo

## Creating a Personal Access Token (if you don't have one)

1. Go to https://github.com/settings/tokens
2. Click "Generate new token"
3. Give it a name (e.g., "GitHub Upload")
4. Check these boxes:
   - `repo` (all)
   - `workflow`
5. Click "Generate token" and copy it
6. Use this token as your password in the git push step above

## Verify It Worked

After pushing, visit:
```
https://github.com/YOUR_USERNAME/mechanical-keyboard-pico
```

You should see your project with the README and all files!

## Next Steps

- Share the GitHub link with others
- People can now view your build documentation
- They can fork your project and make their own version
- Accept pull requests if others contribute improvements
